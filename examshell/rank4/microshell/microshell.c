#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

typedef struct s_cmd
{
	int argc;
	char **argv;
	char **env;
	int fd[2];
	int	redirect_output;
	struct s_cmd *next;
} t_cmd;

int slen(char * s)
{
	int c = 0;
	while (s[c])
		c++;
	return (c);
}

int perr(char *message)
{
	write(1, message, slen(message));
	return (1);
}

int cd(int argc, char **argv)
{
	if(argc != 2)
		return (perr ("error: cd: bad arguments\n"));
	if ( chdir(argv[1]) )
	{
		perr ("error: cd: cannot change directory to ");
		perr (argv[1]);
		return (perr ("\n"));
	}
	return (0);
}

void exec(t_cmd *cmd)
{
	int	pid;

	pipe(cmd->fd);
	pid = fork();
	if(pid) // parent
	{
		close(cmd->fd[1]);
		dup2(cmd->fd[0], 0);
		waitpid(pid, NULL, 0);

	} else {

		close(cmd->fd[0]);
		if (cmd->redirect_output)
			dup2(cmd->fd[1], 1);
		else
			close(cmd->fd[1]);
		if (execve(cmd->argv[0], cmd->argv, cmd->env))
		{
			perr("error: cannot execute ");
			perr(cmd->argv[0]);
			perr("\n");
		}
		exit (0);
	}
}

void push(t_cmd *cmd, char *token)
{
	char **tmp;
	int i = 0;

	tmp = cmd->argv;
	
	cmd->argv = malloc(sizeof(char **) * (cmd->argc + 2));
	if (!cmd->argv)
		return ;
	while (i < cmd->argc)
	{
		cmd->argv[i] = tmp[i];
		i++;
	}
	cmd->argv[i] = token;
	i++;
	cmd->argv[i] = NULL;
	cmd->argc++;
	free(tmp);
}

t_cmd *new_cmd(char **env)
{
	t_cmd *cmd;

	cmd = malloc(sizeof(t_cmd));
	if(!cmd)
		return (NULL);
	cmd->env = env;
	cmd->argc = 0;
	cmd->redirect_output = 0;
	cmd->fd[0] = 0;
	cmd->fd[1] = 0;
	cmd->argv = malloc(sizeof(char **) * (cmd->argc + 1));
	if (cmd->argv)
		*cmd->argv = NULL;
	cmd->next = NULL;
	return (cmd);
}

void free_cmds(t_cmd *cmd)
{
	if (cmd->fd[0])
		close(cmd->fd[0]);
	if (cmd->fd[1])
		close(cmd->fd[1]);
	free (cmd->argv);
}
void free_all_cmds(t_cmd *cmds)
{
	t_cmd *cmd;

	while (cmds)
	{
		free_cmds(cmds);
		cmd = cmds;
		cmds = cmds->next;
		free(cmd);
	}
	
}

void run(t_cmd *cmd)
{
	while (cmd)
	{
		if (cmd->argc == 0)
			return ;
		if (!strcmp (cmd->argv[0], "cd"))
			cd (cmd->argc, cmd->argv);
		else 
			exec(cmd);

		cmd = cmd->next;
	}
}

void parse_cmds(t_cmd **cmds, char *token, char **env)
{
	if (!*cmds)
		*cmds = new_cmd(env);

	if (*token == '|')
	{
		(*cmds)->redirect_output = 1;
		(*cmds)->next = new_cmd(env);
		*cmds = (*cmds)->next;
		return ;
	}
	if (*token == ';')
	{
		(*cmds)->redirect_output = 0;
		(*cmds)->next = new_cmd(env);
		*cmds = (*cmds)->next;
		return ;
	}
	push(*cmds, token);
}

int main(int argc, char **argv, char **env)
{
	t_cmd *cmds = NULL;
	t_cmd *c = NULL;
	int i = 1;

	cmds = new_cmd(env);
	c = cmds;
	while (i < argc)
	{
		parse_cmds(&c, argv[i], env);
		i++;
	}
	run(cmds);
	free_all_cmds(cmds);

	if (TEST)
		while (1);

	return (0);
}
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

typedef struct s_cmd
{
	int 	argc;
	char	**argv;
	char	**env;
	int		fd[2];
	int		redirect;
	struct s_cmd *next;
} t_cmd;

int slen(char *s)
{
	int c = 0;
	while (s[c]) c++;
	return (c);
}

void error(int type, char *s)
{
	char *msg;

	msg = "error :";
	if (type == 0)
		msg = "error: fatal";
	if (type == 1)
		msg = "error: cd: cannot change directory to ";
	if (type == 2)
		msg = "error: cd: bad arguments";
	if (type == 3)
		msg = "error: cannot execute ";
	write(2, msg, slen(msg));
	if (s)
		write(2, s, slen(s));
	write(2, "\n", 1);
	if (type == 0)
		exit (1);
}

t_cmd *new_cmd(char **env)
{
	t_cmd	*cmd;
	int 	i;

	cmd = malloc(sizeof(t_cmd));
	if(!cmd)
		error(0, NULL);
	i = -1;
	while (++i < (int)sizeof(t_cmd))
		*((char *)cmd) = 0;
	cmd->env = env;
	return (cmd);
}

void free_cmd(t_cmd *cmd)
{
	if(cmd->argv)
		free(cmd->argv);
	if(cmd->fd[0])
		close(cmd->fd[0]);
	if(cmd->fd[1])
		close(cmd->fd[1]);
	free (cmd);
}

void push_token(t_cmd *cmd, char *token)
{
	char **sav = cmd->argv;
	int i = -1;
	cmd->argv = malloc(sizeof(char **) * (cmd->argc + 2));
	if (!cmd->argv)
		error(0, NULL);
	while (++i < cmd->argc)
		cmd->argv[i] = sav[i];
	cmd->argv[i] = token;
	cmd->argv[i + 1] = 0;
	cmd->argc++;
}

void cd(t_cmd *cmd)
{
	if (cmd->argc != 2)
		return error(2, NULL);
	if(chdir(cmd->argv[1]))
		return error(1, cmd->argv[1]);
}

void exec_cmd(t_cmd *cmd)
{
	int pid;
	int ret;

	if(pipe(cmd->fd))
		error(0, NULL);
	pid = fork();
	if(pid) //parent
	{
		close(cmd->fd[1]);
		dup2(cmd->fd[0], 0);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(cmd->fd[0]);
		if (cmd->redirect)
			dup2(cmd->fd[1], 1);
		else
			close(cmd->fd[1]);
		ret = execve(cmd->argv[0], cmd->argv, cmd->env);
		if(ret)
			error(3, cmd->argv[0]);
		exit (ret);
	}
}

void run(t_cmd *cmd)
{
	while(cmd)
	{
		if(cmd->argc)
		{
			if(strcmp(cmd->argv[0], "cd") == 0)
				cd(cmd);
			else
				exec_cmd(cmd);
		}
		cmd = cmd->next;
	}
}

int main(int argc, char **argv, char **env)
{
	t_cmd *cmd;
	t_cmd *tmp;
	int i = 0;

	cmd = new_cmd(env);
	tmp = cmd;
	while (++i < argc)
	{
		if (*argv[i] == '|')
		{
			tmp->next = new_cmd(env);
			tmp->redirect = 1;
			tmp = tmp->next;
			continue;
		}
		if (*argv[i] == ';')
		{
			tmp->next = new_cmd(env);
			tmp = tmp->next;
			continue;
		}		
		push_token(tmp, argv[i]);
	}
	run(cmd);
	while (cmd)
	{
		tmp = cmd;
		cmd = cmd->next;
		free_cmd(tmp);
	}
	while (1);
	return (0);	
}
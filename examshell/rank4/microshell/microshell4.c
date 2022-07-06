#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

// codé en 00:56:40

typedef struct s_cmd
{
	int argc;
	char **argv;
	char **env;
	int r;
	int fd[2];
	struct s_cmd *next;
} t_cmd;

int slen (char *s)
{
	int c = 0;
	while(s[c])
		c++;
	return (c);
}

void error(int code, char *t)
{
	char *m = "";
	if (code == 0)
		m = "error: fatal";
	if (code == 1)
		m = "error: cd: bad arguments";
	if (code == 2)
		m = "error: cd: cannot change directory to ";
	if (code == 3)
		m = "error: cannot execute ";
	write(2, m, slen(m));
	if (t)
		write (2, t, slen(t));
	write (2, "\n", 1);
	if (code == 0 || code == 2)
		exit (1);
}

t_cmd *new_cmd(char **env)
{
	t_cmd *cmd;
	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		error(0, NULL);
	for(int i = 0; i < (int)sizeof(t_cmd); i++)
		((char *) cmd)[i] = 0;
	cmd->env = env;
	return (cmd);
}

void clear_cmd(t_cmd *cmd)
{
	if (cmd->argv)
		free(cmd->argv);
	for(int i = 0; i < 2; i++)
		if (cmd->fd[i])
			close(cmd->fd[i]);
	free (cmd);
}

void free_cmd(t_cmd *cmd)
{
	t_cmd * c;
	while(cmd)
	{
		c = cmd;
		cmd = cmd->next;
		clear_cmd(c);
	}
}

void cd (t_cmd *cmd)
{
	if (cmd->argc != 2)
		return error(1, NULL);
	if(chdir(cmd->argv[1]))
		return error(2, cmd->argv[1]);
}

void exec (t_cmd *cmd)
{
	int pid;

	pipe(cmd->fd);
	pid = fork();
	if(pid)
	{
		close(cmd->fd[1]);
		dup2(cmd->fd[0], 0);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(cmd->fd[0]);
		if (cmd->r)
			dup2(cmd->fd[1], 1);
		else
			close(cmd->fd[1]);
		if(execve(cmd->argv[0], cmd->argv, cmd->env))
			error(3, cmd->argv[0]);
	}
}

void add_token(t_cmd *cmd, char *token)
{
	char **argv;

	argv = cmd->argv;
	cmd->argv = malloc(sizeof(char *) * (cmd->argc + 2));
	if (!cmd->argv)
		return error(0, NULL);
	for(int i = 0; i < cmd->argc; i++)
		cmd->argv[i] = argv[i];
	cmd->argv[cmd->argc] = token;
	cmd->argv[cmd->argc + 1] = 0;
	cmd->argc++;
}


void parse (t_cmd **cmd, char *token, char **env)
{
	if (*token == '|')
	{
		(*cmd)->r = 1;
		(*cmd)->next = new_cmd(env);
		(*cmd) = (*cmd)->next;
		return ;
	}
	if (*token == ';')
	{
		(*cmd)->next = new_cmd(env);
		(*cmd) = (*cmd)->next;
		return ;
	}
	add_token(*cmd, token); 
}

int main (int argc, char** argv, char **env)
{
	t_cmd *cmd;
	t_cmd *c;
	cmd = new_cmd(env);
	c = cmd;
	for(int i = 1; i < argc; i++)
		parse(&c, argv[i], env);
	while(cmd)
	{
		if (cmd->argc)
		{
			if (strcmp(cmd->argv[0], "cd") == 0)
				cd(cmd);
			else
				exec(cmd);
		}
		cmd = cmd->next;
	}
	free_cmd(cmd);
	return (0);
}


#include <stdlib.h>
#include <unistd.h>

typedef struct s_cmd
{
	int	fd[2];
	int argc;
	char **argv;
	char **env;
	struct s_cmd *next;
	int redirect;	
}	t_cmd;

int slen(char *s)
{
	int c = 0;
	while (s[c])
		c++;
	return (c);	
}

void fatal_error(void)
{
	char *s;
	s = "error: fatal\n";
	write (2, s, slen(s));
	exit(1);
}

void execute_error(char *filename)
{
	char *s;
	s = "error: cannot execute ";

	write (2, s, slen(s));
	write (2, filename, slen(filename));
	write (2, "\n", 1);
}

t_cmd *new_cmd(char **env)
{
	t_cmd *cmd;
	cmd = malloc(sizeof (t_cmd));
	if (!cmd)
		fatal_error();
	cmd->fd[0] = 0;
	cmd->fd[1] = 0;
	cmd->argc = 0;
	cmd->argv = 0;
	cmd->env = env;
	cmd->redirect = 0;
	cmd->next = 0;
	return (cmd);
}

void clear_cmd(t_cmd *cmd)
{
	if (cmd->fd[0])
		close(cmd->fd[0]);
	if (cmd->fd[1])
		close(cmd->fd[1]);
	if (cmd->argv)
		free(cmd->argv);
}

void execute_cmd(t_cmd *cmd)
{
	int pid;

	pipe(cmd->fd);
	pid = fork();
	if(pid)
	{
		close(cmd->fd[1]);
		dup2(cmd->fd[0], 0);
		waitpid(pid);
	}
	else
	{
		close(cmd->fd[0]);
		if (cmd->redirect)
			dup2(cmd->fd[1], 1);
		else
			close(cmd->fd[1]);

		if (execve(cmd->argv[0], cmd->argv, cmd->env))
			execute_error(cmd->argv[0]);
		exit(1);
	}
}

void push_token(t_cmd *cmd, char *token)
{
	int i;
	char **old;

	old = cmd->argv;
	cmd->argv = malloc(sizeof (char **) * (cmd->argc + 2));
	if (!cmd->argv)
		fatal_error();
	i = -1;
	while (++i < cmd->argc)
		cmd->argv[i] = old[i];
	cmd->argv[i] = token;
	cmd->argv[i + 1] = 0;
	cmd->argc++;
	free(old);
}

void parse_arg(t_cmd **cmd, char *token, char **env)
{
	if (*token == '|')
	{
		(*cmd)->redirect = 1;
		(*cmd)->next = new_cmd(env);
		(*cmd) = (*cmd)->next;
	}
	if (*token == ';')
	{
		(*cmd)->next = new_cmd(env);
		(*cmd) = (*cmd)->next;
	}
	push_token(*cmd, token);
}



int main (int argc, char **argv, char **env)
{
	t_cmd *cmd;
	int i = 1;

	cmd = new_cmd(env);
	while (i < argc)
	{
		parse_arg(&cmd, argv[i], env);
		i++;
	}
	
}

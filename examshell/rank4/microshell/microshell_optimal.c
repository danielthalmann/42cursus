#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>

typedef struct s_cmd
{
	int start;
	int argc;
	char **argv;
	char **env;
	int r;
} t_c;

int slen(char *s)
{
	int c = 0;
	while (s[c]) c++;
	return (c);
}

void error(int c, char *m)
{
	char *t;
	t = "";
	if (c == 0)
		t = "error: fatal";
	if (c == 1)
		t = "error: cd: bad arguments";
	if (c == 2)
		t = "error: cd: cannot change directory to ";
	if (c == 3)
		t = "error: cannot execute ";
	write (2, t, slen(t));
	if (m)
		write(2, m, slen(m));
	write(2, "\n", 1);
	if (c == 1 || c == 3)
		exit (1);
}

void cd ( t_c *c)
{
	if (c->argc != 2)
		return error(1, NULL);
	if (chdir(c->argv[1]))
		return error(2, c->argv[1]);
}

void exec (t_c *c)
{
	int pid;
	int fd[2];

	pipe(fd);
	pid = fork();
	if(pid)
	{
		printf("pid: %d\n", pid);
		close(fd[1]);
		dup2(fd[0], 0);
		waitpid(pid, NULL, 0);
		close(fd[0]);
	} 
	else
	{

		int i;
		for (i = 0; i <= c->argc; i++)
		printf("s: %s\n", c->argv[i]);

		close(fd[0]);
		if (c->r)
			dup2(fd[1], 1);
		else
			close(fd[1]);

		if (execve( c->argv[0], c->argv, c->env))
			error(3, c->argv[0]);
	}
}

void run (t_c *c)
{

//	i = -1;
//	while (c->env[++i])
//		printf("env: %s\n", c->argv[i]);
//

	if(c->argc > 0)
	{
		if(strcmp(c->argv[0], "cd") == 0)
			cd (c);
		else
			exec (c);
	}
}

void trait(t_c *cmd, char **argv, int idx)
{
	if (strcmp(argv[idx], "|") == 0 || strcmp(argv[idx], ";") == 0)
	{
		cmd->r = (strcmp(argv[idx], "|") == 0);
		argv[idx] = 0;
		cmd->argv = (argv + cmd->start);
		run (cmd);
		cmd->argc = 0;
		cmd->start = idx + 1;
		return ;
	}
	cmd->argc++;
}

int main (int argc, char **argv, char **env)
{
	int i = 0;
	static t_c cmd;

	if (argc < 2)
		return (0);
	cmd.start = 1;
	cmd.env = env;
	while(argv[++i])
		trait(&cmd, argv, i);
	cmd.argv = (argv + cmd.start);
	run (&cmd);
	return (0);
}

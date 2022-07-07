#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>

// fait en 00:43:28 

typedef struct s_cmd
{
	int argc;
	char **argv;
	char **env;
	int r;
	int fd[2];
	struct s_cmd *next;
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

t_c *new_cmd(char **env)
{
	t_c *cmd;
	cmd = malloc(sizeof(t_c));
	if (!cmd)
		error(0, NULL);
	for ( int i = 0; i < (int)sizeof(t_c); i++)
		((char*)cmd)[i] = 0;
	cmd->env = env;
	return (cmd);
}

void clear_cmd(t_c *c)
{
	if (c->argv)
		free(c->argv);
	for(int i = 0; i < 2; i++)
		if(c->fd[i])
			close(c->fd[i]);
	free(c);
}

void free_cmd(t_c *c)
{
	t_c *t;
	while(c)
	{
		t = c;
		c = c->next;
		clear_cmd(t);
	}
}

void add_token(t_c *c, char *token)
{
	char **argv;

	argv = c->argv;
	c->argv = malloc(sizeof(char *) * (c->argc + 2));
	if (!c->argv)
		error(0, NULL);
	for ( int i = 0; i < c->argc; i++)
		c->argv[i] = argv[i];
	c->argv[c->argc] = token;
	c->argv[c->argc + 1] = 0;
	c->argc++;
}


t_c *parse(t_c *c, char *token, char **env)
{
	if (*token == '|')
	{
	
		c->next = new_cmd(env);
		c->r = 1;
		return (c->next);
	}
	if (*token == ';')
	{
		c->next = new_cmd(env);
		return (c->next);
	}
	add_token(c, token);
	return (c);
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
	pipe(c->fd);
	pid = fork();
	if(pid)
	{
		close(c->fd[1]);
		dup2(c->fd[0], 0);
		waitpid(pid, NULL, 0);
	} 
	else
	{
		close(c->fd[0]);
		if (c->r)
			dup2(c->fd[1], 1);
		else
			close(c->fd[1]);
		if (execve( c->argv[0], c->argv, c->env))
			error(3, c->argv[0]);
	}
}

void run (t_c *c)
{
	while (c)
	{
		if(c->argc > 0)
		{
//	printf("token %s \n", c->argv[0]);

			if(strcmp(c->argv[0], "cd") == 0)
				cd (c);
			else
				exec (c);
		}
		c = c->next;
	}
}

int main (int argc, char **argv, char **env)
{
	t_c *c;
	t_c *cmd;

	cmd = new_cmd(env);
	c = cmd;
	for(int i = 1; i < argc; i++)
		c = parse(c, argv[i], env);
	run (cmd);
	free_cmd(cmd);
	return (0);
}



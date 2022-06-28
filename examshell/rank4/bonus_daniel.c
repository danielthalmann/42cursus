/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpoltera <lpoltera@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 13:28:02 by lucas             #+#    #+#             */
/*   Updated: 2022/05/03 15:00:48 by lpoltera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*getpath(char *cmd, char **env)
{
	int		i;
	char	*path;
	char	*dir;
	char	*dir_bin;

	i = 0;
	while (env[i] && strncmp(env[i], "PATH=", 5))
		i++;
	path = env[i] + 5;
	while (path && strichr(path, ':') > -1)
	{
		dir = ft_strndup(path, strichr(path, ':'));
		dir_bin = ft_strjoin(dir, cmd);
		if (access(dir_bin, F_OK) == 0)// return 0 if found
			return (dir_bin);
		free(dir_bin);
		path += strichr(path, ':') + 1;
	}
	return (cmd);
}

void	exec(char *cmd, char **env)
{
	char	**cmd_param;
	char	*path;
	//write(1, "been here3\n", 11);
	cmd_param = ft_split(cmd, ' ');
	if (strichr(cmd_param[0], '/') > -1)
	{
		//write(1, "been here4\n", 11);
		path = cmd_param[0];
	}
	else
		path = getpath(cmd_param[0], env);
	if (execve(path, cmd_param, env) == -1)
		perror(path);
}

void	redir_b(char *cmd, char **env, int no)
{
	int	pid;
	int	fd[2];

	pipe(fd);
	pid = fork();
	if (pid != 0)
	{

		close(fd[1]);
		dup2(fd[0], 0);
		waitpid(pid, NULL, 0);
		write(2, "parent\n", 7);
	}
	else
	{
		close(fd[0]);
		if (!no)
			dup2(fd[1], 1);
		write(2, "child\n", 6);
		exec(cmd, env);
	}	
}

int	main(int argc, char **argv, char **env)
{
	int	fdin;
	int	fdout;
	int stdout_save;
	int	i;

	stdout_save = dup(1);
	i = 2;
	if (argc >= 5)
	{
		fdin = open(argv[1], O_RDONLY);
		if (fdin == -1)
		{
			perror(argv[1]);
			exit (1);
		}
		fdout = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);//O_TRUNC efface le contenu si le fichier exite déjà -- S_IRWXU  00700 user (file owner) has read, write, and execute permission
		dup2(fdin, 0);
		dup2(fdout, 1);
		while (i <  argc - 2)
			redir_b(argv[i++], env, 0);
		redir_b(argv[i++], env, 1);
		dup2(stdout_save, 1);
		write(1, "coucou\n", 7);
	}
	else
		write(2, "Invalid number of arguments\n", 28);
}
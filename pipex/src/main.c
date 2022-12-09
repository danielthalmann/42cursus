#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h> 

int pipeint(int in_fd, int with_out, char *prg, char **args, char *envp[])
{
	int pid;
	int r;
    int fd[2];

	if (!last)
    	pipe(fd);

	pid = fork();
	if (pid == -1)
	{
		perror("fork*");
		return (0);
	}
	else if (pid == 0) // enfant
	{
		//sleep(10);
		close(fd[0]); // on ferme le in
		if (in_fd > -1)
			dup2(in_fd,0);
		if (with_out)
			dup2(fd[1],1);
		else
			close(fd[1]);
		if(execve(prg, args, envp))
		{
			perror("pipex");
		}
	} 
	else // parent
	{
		close(fd[1]); // ferme la sortie
		waitpid(pid, NULL, 0);
		if (with_out)
			return (fd[0]);
		else
			close(fd[0]);
	}
	return (0);
}

int main(int argc, char *argv[], char *envp[])
{
	int	i;
	int pid;
	int r;
	char **ar;
	char buff[255];
	int l;
	char *p0[] = {"pid0", 0};
	char *p1[] = {"pid1", 0};

	pid = getpid();
	ar = 0;

	printf("%d : start %s\n", pid, argv[0]);	
	//r = execve("php", argv, envp)

	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	//int in_fd = open("file.log", O_WRONLY | O_CREAT, mode);
	int out_fd = open("in.log", O_RDONLY);

	return (0);

	//perror("res");
	printf("r : %d\n", r);

	pid = getpid();
	i = 0;
	printf("%d : start\n", pid);
	i = fork();
	pid = getpid();

	printf("%d : fork (%d)\n", pid, i);
	i = fork();
	pid = getpid();
	
	printf("%d : fork2 (%d)\n", pid, i); 	
	if (i == 0)
	{
		printf("%d : i am a child\n", pid);
	}
	printf("%d : stop (%d)\n", pid, i);
}

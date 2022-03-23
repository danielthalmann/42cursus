#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h> 

int pipeint(int in_fd, int last, char *prg, char **args, char *envp[])
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

		dup2(in_fd,0);
		if (!last)
		{
			close(fd[0]); // on ferme le in
			dup2(fd[1],1);			
		}
		if(execve(prg, args, envp))
		{
			perror("pipex");
		}
	} 
	else // parent
	{
		waitpid(pid, NULL, 0);		
		if (!last)
		{
			close(fd[1]); // ferme la sortie
			return (fd[0]);
		} 
		else
		{
			return (0);
		}

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

	pid = getpid();
	ar = 0;

	printf("%d : start %s\n", pid, argv[0]);	
	//r = execve("php", argv, envp)

	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	//int in_fd = open("file.log", O_WRONLY | O_CREAT, mode);
	int out_fd = open("in.log", O_RDONLY);

	int fd = pipeint(out_fd, 0, "pid0", argv, envp);
	fd = pipeint(fd, 1, "pid1", argv, envp);
	//do
	//{
	//	l = read(fd, buff, 255);
	//	buff[l] = 0;
	//	printf("%d : read %d : {%s}\n", pid, l, buff);
	//} while (l);

	printf("%d : end \n", pid);

	//close(in_fd);
	wait(NULL);
	
	
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

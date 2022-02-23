#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h> 

int pipeint(int in_fd, int out_fd, char *prg, char **args, char *envp[])
{
	int pid;
	int r;
	int l;
    int fd[2];
	char buff[255];

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
		dup2(in_fd, 0);
		dup2(fd[1],1);
		if(execve(prg, args, envp))
		{
			perror("pipex");
		}
	} 
	else // parent
	{
		close(fd[1]); // ferme la sortie
		dup2(fd[0], out_fd);
		do
		{
			l = read(fd[0], buff, 255 );
			buff[l] = 0;
			printf("read %d : %s\n",l,  buff);
		} while (l);


		waitpid(pid, NULL, 0);
	}
	return (0);
}

int main(int argc, char *argv[], char *envp[])
{
	int	i;
	int pid;
	int r;
	char **ar;

	pid = getpid();
	ar = 0;

	printf("%d : start %s\n", pid, argv[0]);	
	//r = execve("php", argv, envp)

	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	int ffd = open("file.log", O_WRONLY | O_CREAT, mode);

	pipeint(0, ffd, "pid", argv, envp);
	printf("%d : end \n", pid);
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

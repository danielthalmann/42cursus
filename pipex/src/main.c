#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h> 

int pipeint(int in_fd, char *prg, char **args, char *envp[], int idx)
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

		close (fd[0]); // on ferme le in
		dup2(fd[1],1);
		if(execve(prg, args, envp))
		{
			perror("pipex");
		};	
	} else // parent
	{
		close (fd[1]); // ferme la sortie
		
		do
		{
			l = read(fd[0], buff, 255 );
			buff[l] = 0;
			printf("read %d : %s\n",l,  buff);
		} while (l);


		waitpid(pid, NULL, 0);
	}

}

int main(int argc, char *argv[], char *envp[])
{
	int	i;
	int pid;
	int r;
	char **ar;

	pid = getpid();
	ar = 0;

	printf("%d : start %s\n", pid, argv[0], 1);	
	//r = execve("php", argv, envp);


	pipeint(0, "pid", argv, envp);
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

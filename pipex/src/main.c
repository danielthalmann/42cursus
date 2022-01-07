#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
	int	i;
	int pid;
	int r;

	pid = getpid();
	
	printf("%d : start\n", pid);
	r = execve("test", (char**)0,envp);

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

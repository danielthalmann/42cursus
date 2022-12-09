
#include <semaphore.h>
#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	sem_t *s;
	int	n = 3;

	s = sem_open("./test.sem", O_CREAT);
	for(int i=0; i<n; i++)
	{
  	    printf("[%d] fork\n", getpid());
  		fork();
		sem_wait(s);
	}

	printf("[%d] say hello\n", getpid());
	//s = sem_open("./test.sem", O_CREAT);
	//sem_wait(s);
	// sem_close(s);
}
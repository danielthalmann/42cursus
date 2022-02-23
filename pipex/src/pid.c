#include <stdio.h>
#include <unistd.h>
int main(int argc, char ** argv)
{
	int pid = getpid();
	printf("Salut theo\n");
	printf("%d : start pid  %s\n", pid, argv[0]);
	printf("%d : hello i am pid\n", pid);
}

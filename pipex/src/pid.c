#include <stdio.h>
#include <unistd.h>
int main(int argc, char ** argv)
{
	int pid = getpid();
	printf("%d : start %s\n", pid, argv[0]);
	printf("%d : hello i am pid\n", pid);
}

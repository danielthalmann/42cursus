#include <stdio.h>
#include <unistd.h>
int main(int argc, char ** argv)
{
	char buff[15];
	int	len;

	buff[0] = 0;
	len = read(0, buff, 14);
	if (len > -1)
		buff[len] = 0;
	
	int pid = getpid();
	printf("%d : Salut [%s]\n", pid, buff);
	printf("%d : start pid  %s\n", pid, argv[0]);
	printf("%d : hello i am pid\n", pid);
}

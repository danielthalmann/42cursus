#include <stdio.h>
#include <unistd.h>
int main(int argc, char ** argv)
{
	char buff[512];
	int	len;


	buff[0] = 0;
	if (argc < 2){
		len = read(0, buff, 512);
		if (len > -1)
			buff[len] = 0;		
	}

	
	sleep(1);
	int pid = getpid();
	printf("%d : start pid  %s\n", pid, argv[0]);
	printf("%d : read [\n%s]\n", pid, buff);
	printf("%d : hello i am pid\n", pid);
}

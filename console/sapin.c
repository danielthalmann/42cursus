
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> 
#include <stdlib.h>

#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))

#define BUFFSIZE 5


int main (int argc, char **argv)
{
	int flags;
	int size;
	char buf[BUFFSIZE];
	int	fd = 0;

    clear();
	printf("\n");
	printf("        V          \n");
	printf("       >X<         \n");
	printf("        A          \n");
	printf("       dSb         \n");
	printf("     .d\\SSb.      \n");
	printf("   .d$i$$\\$$b.    \n");
	printf("      d$$@b        \n");
	printf("     d\\$$$ib      \n");
	printf("   .d$$$\\$$$b     \n");
	printf(" .d$$#$$$$\\SSib.  \n");
	printf("     d$Si$$b       \n");
	printf("    d\\$$$$#$b     \n");
	printf("  .d$@$\\$$$$$$0.  \n");
	printf(".d$$$$i$$\\$$$$$$b.\n");
	printf("       #4#         \n");
	printf("       #2#         \n");
	printf("       ###         \n");

	flags = fcntl(0, F_GETFL, 0); /* get current file status flags */
	if (fcntl(fd, F_SETFL, flags | O_NONBLOCK) < 0) /* set up non-blocking read */
		exit (1);         

	size = -1;
	while (size == -1)
	{
		usleep(300);
		gotoxy(9, 3);
		printf(".");
		size = read(fd, buf, BUFFSIZE);
		printf("read is egual to [%d], le caractère est [%s]", size, buf);
	}
	return (0);
}
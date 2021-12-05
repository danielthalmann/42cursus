
#include <stdio.h>

#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))


int main (int argc, char **argv)
{
	int number;

    clear();
    printf(
        "Enter your number in the box below\n"
        "+-----------------+\n"
        "|                 |\n"
        "+-----------------+\n"
    );
    gotoxy(2, 3);
    scanf("%d", &number);

	return (0);
}
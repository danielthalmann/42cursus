
#include <unistd.h>
int	in_perimeter(int x, int y, int r)
{
	return ( ((x * x) + (y * y) < (r * r)) && ((x * x) + (y * y) > ((r-1) * (r-1))));
}

int	main(int argc, char **argv)
{

	int width;
	int height;
	int x, y;
	int cx, cy, cr;


	width = 50;
	height = 50;

	cx = 10;
	cy = 10;
	cr = 7;

	y = 0;
	while(y < height)
	{
		x = 0;
		while (x < width)
		{
			if (in_perimeter(x - cx, y - cy, cr))
			{
				write (1, "#", 1);		
			}
			else
			{
				write (1, "*", 1);
			}
			x++;
		}
		
		write (1, "\n", 1);
		y++;
	}
}
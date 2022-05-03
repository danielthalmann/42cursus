
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_a
{
	int w;
	int h;
	int s;
	char c; // color
	char *a; // array
} t_a;

int slen(char *s)
{
	int c = 0;
	while (s[c])
		c++;
	return (c);
}

void print(int fd, char *s)
{
	write (fd, s, slen(s));
}

int perr(char *s, FILE *f, t_a *t)
{
	print(2, s);
	if (t)
	{
		if (t->a)
			free(t->a);
	}
	if (f)
		fclose(f);
	return (1);
}

int in_shape(float x, float y, float tx, float ty, float bx, float by)
{
	if (x < tx || x > bx || y < ty || y > by)
		return (0);
	if (x - tx < 1.0 || bx - x < 1.0 || y - ty < 1.0 || by - y < 1.0)
	       return (2);
	return (1);
}	

int readshape(FILE *f, t_a *a)
{
	int l, i;
	int r;
	float x, y, w, h;
	char c, t;

	while(1)
	{
		l = fscanf(f, "%c %f %f %f %f %c\n", &t, &x, &y, &w, &h, &c);
		if (l == -1)
			return (1);
		if (l != 6)
			return (0);
		if (w <= 0 || h <= 0 || !(t == 'r' || t == 'R'))
			return (0);
		i = 0;
		while (i < a->s)
		{
			r = in_shape(i % a->w, i / a->w, x, y, x + w, y + h);
		
//			if (r)	
				if (r == 2 || (t == 'R' && r == 1))
					a->a[i] = c;
			i++;
		}
	}
	return (1);
}

int readf(FILE *f, t_a *a)
{
	int l;

	l = fscanf(f, "%d %d %c\n", &a->w, &a->h, &a->c);
	if (l != 3)
			return (0);
	if (a->w < 1 || a->w > 300 || a->h < 1 || a->h > 300)
			return (0);
	a->s = a->w * a->h;
	a->a = (char *)malloc(sizeof(char) * a->s);
	if (! a->a )
			return (0);
	for ( int i = 0; i < a->s; i++)
		a->a[i] = a->c;
	
	return (readshape(f, a));
}

void draw(t_a *a)
{
	int i = -1;
	while (++i < a->h)
	{
		write(1, &a->a[i * a->w], a->w);
		write (1, "\n", 1);
	}

}

int main(int argc, char **argv)
{
	t_a a;
	FILE *f;
	
	if (argc != 2)
		return (perr("Error: argument\n", NULL, NULL));

	if ( !(f = fopen(argv[1], "r") ) )
		return (perr("Error: Operation file corrupted\n", NULL, NULL));

	if (!readf(f, &a))
		return (perr("Error: Operation file corrupted\n", NULL, NULL));

	fclose(f);
	draw (&a);
	free(a.a);
	return (0);
}

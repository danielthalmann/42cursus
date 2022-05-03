#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>


typedef struct s_a
{
	int width;
	int height;
	int size;
	char *v;
} t_a;

int slen(char *s)
{
	int c = 0;
	while (s[c]) c++;
	return (c);
}

void print(int fd, char* s)
{
	write (fd, s, slen(s));
}

float dbl(float v)
{
	return (v * v);
}

int hitshape(float x, float y, float cx, float cy, float r)
{
	float cr = sqrtf(dbl(cx - x) + dbl(cy - y));
	if (cr > r)
		return (0);
	if (r - cr < 1.0)
		return (1);
	return (2);
}

int readshape(FILE *f, t_a *a)
{
	float x, y, r;
	int i, hit;
	char c, t;

	while (1)
	{
		i = fscanf(f, "%c %f %f %f %c\n", &t, &x, &y, &r, &c);
		if(i == -1)
			return (1);
		if(i != 5)
			return (0);
		if(!(t == 'c' || t == 'C') || r <= 0 )
			return (0);
		i = 0;
		while (i < a->size)
		{
			hit = hitshape(i % a->width, i / a->width, x, y, r);
			if (hit == 1 || (hit == 2 && t == 'C'))
				a->v[i] = c;
			i++;
		}
	}
}

int readhead(FILE *f, t_a *a)
{
	int i;
	char c;

	i = fscanf(f, "%d %d %c\n", &a->width, &a->height, &c);
	if (i != 3)
		return (0);
	if(a->width < 1 || a->width > 300 || a->height < 1 || a->height > 300)
		return (0);
	a->size = a->width * a->height;
	a->v = malloc(a->size * sizeof(char));
	if (!a->v)
		return (0);
	i = 0;
	while (i < a->size)
	{
		a->v[i] = c;
		i++;
	}
	return (readshape(f, a));
}

int perr(char *s, FILE *f, t_a *a)
{
	print(2, s);
	if (f)
		fclose(f);
	if (a && a->v)
		free(a->v);
	return (1);
}

void draw (t_a *a)
{
	int i;
	i = 0;
	while (i < a->height)
	{
		write(1, &a->v[i * a->width], a->width);
		write(1, "\n", 1);
		i++;
	}
}

int main(int argc, char **argv)
{
	FILE *f;
	static t_a a;
	

	if (argc != 2)
		return (perr("Error: argument\n", NULL, NULL));
	if (!(f = fopen(argv[1], "r")))
		return (perr("Error: Operation file corrupted\n", f, NULL));
	if (!readhead(f, &a))
		return (perr("Error: Operation file corrupted\n", f, &a));
	draw(&a);
	fclose(f);
	free(a.v);
	return (0);
}

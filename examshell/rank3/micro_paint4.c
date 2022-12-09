#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
typedef struct s_a
{
	int w;
	int h;
	int s;
	char *a;
} t_a;


int slen(char *s)
{
	int c = 0;
	while (s[c]) c++;
	return (c);
}

int hit_shape(float x, float y, float tx, float ty, float bx, float by)
{
	if (x < tx || x > bx || y < ty || y > by)
		return (0);
	if (x - tx < 1.0 || bx - x < 1.0 || y - ty < 1.0 || by - y < 1.0)
		return (1);
	return (2);
}

int read_shape(FILE *f , t_a *a)
{
	int i, hit;
	float x, y, w, h;
	char t, c;
	while (1)
	{
		i = fscanf(f, "%c %f %f %f %f %c\n", &t, &x, &y, &w, &h, &c);
		if (i == -1) return (1);
		if (i != 6) return (0);
		if (w < 1.0  || h < 1.0 || (t != 'r' && t != 'R' )) return (0);
		i = 0;
		while (i < a->s)
		{
			hit = hit_shape(i % a->w, i / a->w, x, y, x + w, y + h);
			if ((hit == 2 && t == 'R') || hit == 1)
				a->a[i] = c;
			i++;
		}
		
	}
	return (1);
}

int read_head(FILE *f , t_a *a)
{
	int i;
	char c;
	i = fscanf(f, "%d %d %c\n", &a->w, &a->h, &c);
	if (i != 3) return (0);
	if (a->w < 1 || a->w > 300 || a->h < 1|| a->h > 300) return (0);
	a->s = a->w * a->h;
	a->a = malloc(a->s);
	if (!a->a) return (0);
	i = 0;
	while (i < a->s)
	{
		a->a[i++] = c;  
	}
	
	memset(a->a, a->s, c);
	return (1);
}

void draw(t_a *a)
{
	int i = 0;
	while (i < a->h)
	{
		write (1, &a->a[i * a->w], a->w);
		write (1, "\n", 1);
		i++;
	}

}

int perr(char *s, FILE *f, t_a *a)
{
	write(2, s, slen(s));
	if (f) fclose(f);
	if (a && a->a) free(a->a);
	return (1);
}

int main (int argc, char **argv)
{
	FILE *f;
	static t_a a;

	if (argc != 2)
		return (perr("Error: argument\n", NULL, NULL));
	if (!(f = fopen(argv[1], "r")))
		return (perr("Error: Operation file corrupted\n", NULL, NULL));
	if (!read_head(f, &a))
		return (perr("Error: Operation file corrupted\n", f, &a));
	if (!read_shape(f, &a))
		return (perr("Error: Operation file corrupted\n", f, &a));
	draw(&a);
	fclose(f);
	free(a.a);
	return (0);
}

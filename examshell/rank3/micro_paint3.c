
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

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

int perr(char *s, FILE *f, t_a *a)
{
	write (2, s, slen(s));
	if (f)
		fclose(f);
	if (a && a->a)
		free(a->a);
}

int ishit(float x, float y, float tx, float ty, float bx, float by)
{
	if (x < tx || x > bx || y < ty || y > by)
		return (0);
	if (x - tx < 1.0 || bx - x < 1.0 || y - ty < 1.0 || by - y < 1.0)
		return (1);
	return (2);
}

int read_shape(FILE *f, t_a *a)
{
	float rx, ry, rw, rh;
	char rt, rc;
	int i, h;

	while (1)
	{
		i = fscanf(f, "%c %f %f %f %f %c\n", &rt, &rx, &ry, &rw, &rh, &rc);
		if (i == -1) return (1);
		if (i != 6) return (0);
		if (rw < 1.0 || rh < 1.0 || (rt != 'r' && rt != 'R')) return (0);
		i = 0;
		while (i < a->s)
		{
			h = ishit(i % a->w, i / a->w, rx, ry, rx + rw, ry + rh);
			// printf("%d", h);
			if (h == 1 || ( rt == 'R' && h == 2))
				a->a[i] = rc;
			i++;
		}
	}
	return (1);
}

int read_head(FILE *f, t_a *a)
{
	int i;
	char c;
	
	i = fscanf(f, "%d %d %c\n", &(a->w), &(a->h), &c);
	if (i != 3) return (0);
	a->s = a->w * a->h;
	a->a = malloc(a->s);
	if (!a->a) return (0);
	i = 0;
	while (i < a->s)
		a->a[i++] = c;
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

int main ( int argc, char **argv)
{
	FILE *f;
	static t_a a;

	if (argc != 2)	return (perr("Error", NULL, NULL));
	if (!(f = fopen(argv[1], "r")))	return (perr("Error", NULL, NULL));
	if (!read_head(f, &a)) return (perr("Error", f, &a));
	if (!read_shape(f, &a)) return (perr("Error", f, &a));
	draw(&a);
	fclose(f);
	free(a.a);
	return (0);
}
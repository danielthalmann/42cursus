#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_shape
{
	char	s;
	float	x;
	float	y;
	float	w;
	float	h;
	char	c;
	
} t_shape;

typedef struct s_scr
{
	int w;
	int h;
	char c;
	char *a;
} t_scr;

int _strlen(char *s)
{
	int c = 0;
	while (s && s[c])
		c++;
	return (c);
}

void print(int fd, char *s)
{
	write(fd, s, _strlen(s));
}

int error_print(char* s, FILE *f, t_scr *scr)
{
	if (f)
		fclose(f);
	if (scr && scr->a)
		free(scr->a);
	print(2, s);
	return (1);
}

int shapeHit(int x, int y, t_shape *shape)
{
	if (x < shape->x && x > shape->x + shape->w &&
		y < shape->y && y > shape->y + shape->h)
	return (0);

	if (shape->x - x < 1.0 || x - (shape->x + shape->w) < 1.0 ||
		shape->y - y < 1.0 || y - (shape->y + shape->h) < 1.0 
	)
		return (1);
	return (2);

}

void setShape(t_shape *shape, t_scr *scr)
{
	for (int y = 0; y < scr->h; y++)
	{
		for(int x = 0; x < scr->w; x++)
		{
			int hit = shapeHit(x, y, shape);
			if (hit)
			{
				printf("", );
				if (shape->s == 'R' || shape->s == 'r' && hit == 1)
					scr->a[x + (y * scr->w)] = shape->c;
			}

		}
	}
}

int read_file(FILE *f, t_scr *scr)
{
	int l;
	t_shape shape;
	int i = 0;

	l = fscanf(f, "%d %d %c\n", &scr->w, &scr->h, &scr->c);
	if (l != 3)
		return (0);
	if (scr->w <= 0 || scr->h <= 0)
		return (0);
	if (!(scr->a = malloc(scr->h * scr->w * sizeof(char))))
		return (0);

	while (i < (scr->w * scr->h))
		scr->a[i++] = scr->c;
	
	while(1)
	{
		l = fscanf(f, "%c %f %f %f %f %c\n", &shape.s, &shape.x, &shape.y, &shape.w, &shape.h, &shape.c);
		if (l == -1)
			return (1);
		if (l != 6)
			return (0);
		if ((shape.s != 'r' && shape.s != 'R') || shape.w <= 0 || shape.h <= 0)
			return (0);
		setShape(&shape, scr);
	}

	return (1);	
}

void draw(t_scr *scr)
{
	for (int y = 0; y < scr->h; y++)
	{
		for(int x = 0; x < scr->w; x++)
		{
			write(1, &(scr->a[x + (y * scr->w)]), 1);
		}
		write (1, "\n", 1);
	}
}

int main (int argc, char **argv)
{
	FILE *f;
	t_scr scr;
	scr.a = 0;

	
	if (argc != 2)
		return (error_print("Error: argument\n", 0, 0));
	if((f = fopen(argv[1], "r")) == 0)
		return (error_print("Error: Operation file corrupted\n", 0, 0));
	if(!read_file(f, &scr))
		return (error_print("Error: Operation file corrupted\n", f, &scr));
	fclose(f);
	draw(&scr);
	free(scr.a);
	return (0);
		
}
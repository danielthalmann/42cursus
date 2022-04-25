#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

//#define _MICRO_PAINT_  
#define _MINI_PAINT_  

#ifdef _MICRO_PAINT_
typedef struct s_rect
{
	char	s;
	float	x;
	float	y;
	float	w;
	float	h;
	char	c;
	
} t_rect;

#endif
#ifdef _MINI_PAINT_

typedef struct s_sphere
{
	char	s;
	float	x;
	float	y;
	float	r;
	char	c;
	
} t_sphere;
#endif


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

#ifdef _MICRO_PAINT_

int rectHit(int x, int y, t_rect *rect)
{
	if (x < rect->x || x > rect->x + rect->w ||
		y < rect->y || y > rect->y + rect->h)
	return (0);

	if (x - rect->x < 1.0 || (rect->x + rect->w) - x < 1.0 ||
		y - rect->y < 1.0 || (rect->y + rect->h) - y < 1.0 
	)
		return (1);
	return (2);

}

void setRect(t_rect *rect, t_scr *scr)
{
	for (int y = 0; y < scr->h; y++)
	{
		for(int x = 0; x < scr->w; x++)
		{

			int hit = rectHit(x, y, rect);
			if (hit == 1 || (rect->s == 'R' && hit == 2))
				scr->a[x + (y * scr->w)] = rect->c;
		}
	}
}



#endif
#ifdef _MINI_PAINT_

float square(float v)
{
	return (v * v);
}

int sphereHit(int x, int y, t_sphere *sphere)
{
	float r;
	r = sqrtf( square (sphere->x - x) + square (sphere->y - y) );
	if (r > sphere->r )
		return (0);
	if (sphere->r - r < 1.0)
		return (1);
	return(2);

}


void setSphere(t_sphere *sphere, t_scr *scr)
{
	for (int y = 0; y < scr->h; y++)
	{
		for(int x = 0; x < scr->w; x++)
		{
			int hit = sphereHit(x, y, sphere);
			if (hit == 1 || (sphere->s == 'C' && hit == 2))
				scr->a[x + (y * scr->w)] = sphere->c;

		}
	}
}

#endif


int read_file(FILE *f, t_scr *scr)
{
	int l;
	int i = 0;
#ifdef _MICRO_PAINT_
	t_rect rect;

#endif
#ifdef _MINI_PAINT_
	t_sphere sphere;
#endif
	l = fscanf(f, "%d %d %c\n", &scr->w, &scr->h, &scr->c);
	if (l != 3)
		return (0);
	if (scr->w < 1 || scr->h < 1 || scr->h > 300 || scr->w > 300)
		return (0);
	if (!(scr->a = malloc(scr->h * scr->w * sizeof(char))))
		return (0);

	while (i < (scr->w * scr->h))
		scr->a[i++] = scr->c;
	
	while(1)
	{
#ifdef _MICRO_PAINT_
		l = fscanf(f, "%c %f %f %f %f %c\n", &rect.s, &rect.x, &rect.y, &rect.w, &rect.h, &rect.c);
		if (l == -1)
			return (1);
		if (l != 6)
			return (0);
		if ((rect.s != 'r' && rect.s != 'R') || rect.w <= 0 || rect.h <= 0)
			return (0);
		setRect(&rect, scr);

#endif
#ifdef _MINI_PAINT_
		l = fscanf(f, "%c %f %f %f %c\n", &sphere.s, &sphere.x, &sphere.y, &sphere.r, &sphere.c);
		if (l == -1)
			return (1);
		if (l != 5)
			return (0);
		if ((sphere.s != 'c' && sphere.s != 'C') || sphere.r <= 0)
			return (0);
		setSphere(&sphere, scr);

#endif
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

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_scene
{
	float w;
	float h;
	char c;
	char *a;
} t_scene;

typedef struct s_shape
{
	char t;
	float x;
	float y;
	float w;
	float h;
	float r;
	char c;
} t_shape;

int slen(char* s)
{
	int c = 0;
	while (s[c])
		c++;
	return (c);
}

void pt(char *s)
{
	write(1, s, slen(s));
}

int perr(char *s, FILE *f, t_scene *sc)
{
	if (f) 
		fclose(f);
	if (sc && sc->a)
		free(sc->a);
	pt(s);
	return (1);
}

void set_a(t_scene *sc, int x, int y, char c)
{
	sc->a[(int)x + (int)(y * sc->w)] = c;
}

float sq(float v)
{
	return (v * v);
}

int in_shape_c(t_shape *s, int x, int y)
{
	float d = sqrtf(sq(x - s->x) + sq(y - s->y));
	if (d > s->r)
		return (0);
	if (s->r - d < 1.0)
		return (1);
	return (2);
}

int in_shape_r(t_shape *s, int x, int y)
{
	
	if (x < s->x || x > s->x + s->w || 
	    y < s->y || y > s->y + s->h)
		return (0);
	if (x - s->x <= 1.0 || y - s->y <= 1.0
	   || (s->x + s->w) - x <= 1.0 || (s->y + s->h) - y <= 1.0 )
		return (1);
	return (2);
}

void apply_shape(t_scene *sc, t_shape *s)
{
	int x;
	int y;
	int r;

	y = 0;
	while(y < sc->h)
	{
		x = 0;
		while(x < sc->w)
		{
			if (s->t == 'C' || s->t == 'c')
			{
				r = in_shape_c(s, x, y);
				if ((s->t == 'C' && r) || (s->t == 'c' && r == 1))
					set_a(sc, x, y, s->c);
			}
			else
			{
				r = in_shape_r(s, x, y);
				if ((s->t == 'R' && r) || (s->t == 'r' && r == 1))
					set_a(sc, x, y, s->c);
				
			}
			x++;
		}
		y++;
	}

}

int parse_shape(FILE *f, t_scene *sc)
{
	int r;
	t_shape s;


	r = 0;
	while (r != -1)
	{

		r = fscanf(f, "%c", &s.t);
		if (r == -1)
			return (1);
		if (r != 1)
			return (0);
		if (s.t == 'c' || s.t == 'C'){
			r = fscanf(f, "%f %f %f %c\n", &s.x, &s.y, &s.r, &s.c);
//			printf("r %d c: %c \n", r, s.t);
			if (r != 4 && r != -1)
				return (0);
			if (s.r <= 0)
				return (0);
		}
		else if (s.t == 'r' || s.t == 'R')
		{
			r = fscanf(f, "%f %f %f %f %c\n", &s.x, &s.y, &s.w, &s.h, &s.c);
			if (r != 5)
				return (0);
		} 
		else
			return (0);
		
		apply_shape(sc, &s);
	}
	return (1);
}

int parse_scene(FILE *f, t_scene *sc)
{
	int r;
	int x = 0;
	int y = 0;
	
	r = fscanf(f, "%f %f %c\n", &sc->w, &sc->h, &sc->c);
 //	printf("r %d c = [%c]\n", r, (sc->c));
	if (r != 3)
		return (0);
	if(sc->c == ' ')
		return (0);

	if(sc->w < 1 || sc->w > 300.0 || sc->h < 1 || sc->h > 300.0)
		return (0); 
	sc->a = malloc(sc->w * sc->h);
	if (sc->a)
	{
		x = 0;
		while(x < sc->w)
		{
			y = 0;
			while( y < sc->h)
			{
				set_a(sc, x, y, sc->c);
				y++;
			}
			x++;
		}
	
		return (1);
	}
	return (0);
}

void draw_scene(t_scene *sc)
{
	int x = 0;
	int y = 0;

	y = 0;
	while(y < sc->h)
	{
		x = 0;
		while(x < sc->w)
		{
			write(1, &sc->a[x + (int) (y * sc->w)], 1);
			x++;
		}
		y++;
		write (1, "\n", 1);
	}
}

int main(int argc, char** argv)
{
	FILE *f;
	static t_scene sc;

	if (argc != 2)
		return (perr("Error: argument\n", NULL, NULL));
//	pt(argv[1]);
	f = fopen(argv[1], "r");
	if (!f)
		return (perr("Error: Operation file corrupted\n", NULL, NULL));
	if (!parse_scene(f, &sc))
		return (perr("Error: Operation file corrupted\n", f, NULL));
	if (!parse_shape(f, &sc))
		return (perr("Error: Operation file corrupted\n", f, &sc));
	draw_scene(&sc);
	free(sc.a);
	fclose(f);
	return (0);	

}	

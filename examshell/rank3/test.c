
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>


typedef struct s_shape
{
	char t;
	float x;
	float y;
	float r;
	float w;
	float h;
	char c;
} t_shape;

typedef struct s_app
{
	float w;
	float h;
	char c;
	char *arr;
	FILE *f;
} t_app;


int slen (char *s)
{
	int c = 0;
	while (s && s[c])
		c++;
	return (c);
}

void p(int fd, char* s)
{
	write (fd, s, slen(s));
}

int perr(char *s, t_app *app)
{
	if (app->f)
		fclose(app->f);
	if (app->arr)
		free(app->arr);
	p (2, s);
	return (1);
}

float square(float v)
{
	return (v * v);
}

int in_circle (t_shape *c, float x, float y)
{
	float r = sqrtf(square(c->x - x) + square(c->y - y));
	if (c->r <= r)
	{


	}

}

int parse_size(FILE *f, t_app *app)
{
	int i;

	i = fscanf(f, "%f %f %c\n", &app->w, &app->h, &app->c);
	if (i != 3)
		return (0);
	if (app->w <= 0.0 || app->w > 300 || app->h <= 0.0 || app->h > 300)
		return (0);
	app->arr = malloc(sizeof(char) * app->w * app->h);
	if (!app->arr)
		return (0);	
	i = -1;
	while (++i < app->w * app->h)
		app->arr[i] = app->c;
}


void  draw(t_app *app)
{
	int x, y;
	y = -1;
	while (++y < app->h)
	{
		x = -1;
		while (++x < app->w)
			write (1, &(app->arr[(int)x + (int)(y * app->w)]), 1);
		write(1, "\n", 1);
	}
}

float sq(float v)
{
	return (v * v);
}


int in_shape(float x, float y, t_shape *s)
{
	float d = sqrtf(sq(s->x - x) + sq(s->y - y));
	if(d > s->r)
		return (0);
	return (1);
}

void  apply_shape(t_app *app, t_shape *s)
{
	int x, y;
	y = -1;
	while (++y < app->h)
	{
		x = -1;
		while (++x < app->w)
		{
			if(in_shape(x, y, s))
				app->arr[(int)x +(int)(y * app->w)] = s->c;
	
		}
	}
}

int parse_shape(t_app *app)
{
	int i = 0;
	t_shape s;

	while (i != -1)
      	{
		i = fscanf(app->f, "%c %f %f %f %c\n", &s.t, &s.x, &s.y, &s.r, &s.c);
		if (i == -1)
			return (1);
		if (i != 5)
		       return (0);
		if (s.r <= 0 || (s.t != 'c' && s.t != 'C'))
			return (0);
		apply_shape(app, &s);

	} 
	return (1);
}

int main (int argc, char** argv)
{

	int a, b, c;
	static t_app app;


	if (argc != 2)
		return (perr("error parameter\n", &app));
	app.f = fopen(argv[1], "r");
	if (!app.f)
		return (perr("not file \n", &app));
	if (!parse_size(app.f, &app))
		return (perr("1) not valid \n", &app));
	if (!parse_shape(&app))
		return (perr("2) not valid \n", &app));
	draw(&app);
	fclose(app.f);
}


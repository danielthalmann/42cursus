// Programmer: Mihalis Tsoukalos
// Date: Wednesday 04 June 2014
//
// A simple OpenGL program that draws a triangle.

#include "GL/freeglut.h"
#include "GL/gl.h"

void drawTriangle()
{
    glClearColor(0.4, 0.4, 0.4, 0.4);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

        glBegin(GL_TRIANGLES);
                glVertex3f(-0.7, 0.7, 0);
                glVertex3f(0.7, 0.7, 0);
                glVertex3f(0, -1, 0);
        glEnd();

    glFlush();
}

void ft_push_swap_test(t_swap *lists)
{
	ft_print_swap(lists);
	ft_reverse_rotate_a(lists);
	ft_print_swap(lists);
	ft_reverse_rotate_a(lists);
	ft_print_swap(lists);
	ft_reverse_rotate_a(lists);
	ft_push_a(lists);
	ft_push_a(lists);
	ft_push_a(lists);
	ft_push_a(lists);
	ft_print_swap(lists);
	ft_push_a(lists);
	ft_print_swap(lists);
	ft_rotate_b(lists);
	ft_print_swap(lists);
	ft_rotate_b(lists);
	ft_print_swap(lists);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL - Creating a triangle");
    glutDisplayFunc(drawTriangle);
    glutMainLoop();
    return 0;
}

#include "Drawer.h"
#include <GL/glut.h>

Drawer drw;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	drw.DrawAll();
	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("3D Engine");
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, WIDTH, HEIGHT, 0.0);
	glutFullScreen();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
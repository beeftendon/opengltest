#include <math.h>
#include <freeglut.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <dos.h>
#include <windows.h>
using namespace std;

float angle = 0.0, deltaAngle = 0.0, ratio;
float x = 0.0f, y = 1.75f, z = 5.0f;
float lx = 0.0f, ly = 0.0f, lz = -1.0f;
GLint snowman_display_list;
int deltaMove = 0;
float a = 0.0f;
int b = 0;

void changeSize(int w, int h)
{

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;

	ratio = 1.0f * w / h;
	// Reset the coordinate system before modifying
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the clipping volume
	gluPerspective(45, ratio, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void renderScene(void)
{
	FILE *file;
	float numbers[3];
	float rx, ry, rz;
	int i;
	// THis is used to set Z position.
	static float nZ = -10.0;
	glLoadIdentity();
	gluLookAt(0.0f, 0.0f, nZ, 0.0f, 0.0f, 0.f, 0.0f, 1.0f, 0.0f);
	glFlush();

	// Next time Z position changes.
	nZ -= 0.125;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutWireCube(2.0f);
	glutPostRedisplay();
	glutSwapBuffers();
}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 360);
	glutCreateWindow("My animation");
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);

	glutMainLoop();

	return(0);
}
#include <math.h>
#include <freeglut.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <dos.h>
#include <windows.h>
#include "stimulus.h"
using namespace std;

float angle = 0.0, deltaAngle = 0.0, ratio;
float x = 0.0f, y = 1.75f, z = 5.0f;
float lx = 0.0f, ly = 0.0f, lz = -1.0f;
GLint snowman_display_list;
int deltaMove = 0;
float a = 0.0f;
int b = 0;
float nZ = -5;

double PCFreq = 0.0;
__int64 CounterStart = 0;
void StartCounter()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		cout << "QueryPerformanceFrequency failed!\n";

	PCFreq = double(li.QuadPart) / 1000.0;

	QueryPerformanceCounter(&li);
	CounterStart = li.QuadPart;
}
double GetCounter()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart - CounterStart) / PCFreq;
}


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
	//static float nZ = -10.0;
	glLoadIdentity();
	gluLookAt(0.0f, 0.0f, nZ, 0.0f, 0.0f, 0.f, 0.0f, 1.0f, 0.0f);
	glFlush();

	// Next time Z position changes.
	//nZ -= 0.125;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_QUADS);
	glVertex3f(-1.0f, 1.0f, 0.0f);              // Top Left
	glVertex3f(1.0f, 1.0f, 0.0f);              // Top Right
	glVertex3f(1.0f, -1.0f, 0.0f);              // Bottom Right
	glVertex3f(-1.0f, -1.0f, 0.0f);              // Bottom Left
	glEnd();                            // Done Drawing The Quad

	glutPostRedisplay();
	glutSwapBuffers();

	return;
}

void mouse(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN)
	{
		nZ -= 1;
	}
	glutPostRedisplay();
}

int main(int argc, char **argv)
{
	double loop_timer = 0;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 360);
	glutCreateWindow("My animation");
	glutDisplayFunc(drawCylinderBarsES);
	glutMouseFunc(mouse);
	glutReshapeFunc(changeSize);

	StartCounter();
	while (true)
	{
		loop_timer = GetCounter();
		while (GetCounter() - loop_timer < 16.0)
		{
		};
		tc = GetCounter();
		glutMainLoopEvent();

	}

	return(0);
}
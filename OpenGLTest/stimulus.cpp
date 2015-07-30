#include "stimulus.h"

void drawCylinderBarsES(float tc)
{
	int ii;
	//float startpos = Stimulus.spacing; // degrees, where first bar is drawn
	float startpos = 180;
	float startpos_i;
	float width = 5; // degrees
	float r = 30; // arbitrary radius, doesn't matter for now since everything else is in degrees
	float added; // 090302, added this to get rid of stimrot.mean rotation, not useful for me here...

	if (tc <= Stimulus.tau2) // pause time before things move
		added = 0;
	else
		added = (tc - Stimulus.tau2)*Stimulus.stimrot.mean;  // put in translation mean here to get easy spinning. not ideal... bring amp back to 0 though!

	float height = 5 * r; // arbitrary number just to cover the screen
	float x1;
	float z1;
	float x2;
	float z2;

	startpos_i = startpos - 80 * tc;
	glPushMatrix();
	for (int i = 0; i < 36; i++)
	{
		float x1 = r*cos(startpos_i*3.14159 / 180);
		float z1 = -r*sin(startpos_i*3.14159 / 180);
		float x2 = r*cos((startpos_i - width)*3.14159 / 180);
		float z2 = -r*sin((startpos_i - width)*3.14159 / 180);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 1);
		glBegin(GL_QUADS);
		// Draw the vertices in CCW order
		glVertex3f(x1, height / 2, z1); // top left
		glVertex3f(x1, -height / 2, z1); // bottom left
		glVertex3f(x2, -height / 2, z2); // bottom right
		glVertex3f(x2, height / 2, z2); // top right
		glEnd();

		startpos_i -= 2 * width;
	};
	glPopMatrix();
};
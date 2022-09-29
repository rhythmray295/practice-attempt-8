//
//  Main3.cpp
//

#include <string>
#include "ObjLibrary/Vector2.h"
#include "GetGlut.h"
#include "Sleep.h"
#include "Square.h"

using namespace std;
using namespace ObjLibrary;

// prototypes
void initDisplay();
void keyboard(unsigned char key, int x, int y);
void update();
void reshape(int w, int h);
void display();
bool isAlive;

// declare global variables here
const unsigned int SQUARE_COUNT = 100;
Square squares[SQUARE_COUNT];
unsigned int next_square = 0;
bool emitter_on = true;
bool red_color_increase = true;
bool red_color_decrease = true;
bool green_color_increase = true;
bool green_color_decrease = true;
bool blue_color_increase = true;
bool blue_color_decrease = true;
bool white_color_increase = true;
bool transparent = true;
bool speed_increase = true;
bool speed_decrease = true;
bool clockwise = true;
bool anti_clockwise = true;

int main (int argc, char** argv)
{
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
	glutCreateWindow("Particles");
	glutKeyboardFunc(keyboard);
	glutIdleFunc(update);
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);

	initDisplay();

	glutMainLoop();

	return 1;
}




void initDisplay()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27: // on [ESC]
		exit(0); // normal exit
		break;
	case ' ': // on [SPACEBAR]
		emitter_on = !emitter_on;
		break;
	case '8': // on [SPACEBAR]
		speed_increase = !speed_increase;
		break;
	case '2': // on [SPACEBAR]
		speed_decrease = !speed_decrease;
		break;
	case 4: // on [SPACEBAR]
		anti_clockwise = !anti_clockwise;
		break;
	case 6: // on [SPACEBAR]
		 clockwise = !clockwise;
		break;
	case 'R':
		red_color_increase = !red_color_increase;
		break;
	case 'G':
		green_color_increase = !green_color_increase;
		break;

	case 'B':
		blue_color_increase = !blue_color_increase;
		break;
	case 'r':
		blue_color_increase = !blue_color_increase;
		break;
	case 'g':
		white_color_increase = !white_color_increase;
		break;
	case 'b':
		white_color_increase = !white_color_increase;
		break;
	case 'T':
		transparent = !transparent;
		break;
	}
}



void reshape(int w, int h)
{
	glViewport (0, 0, w, h);

	int x_center = w / 2;
	int y_center = h / 2;

	// set up a 2D view
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-x_center, w - x_center, -y_center, h - y_center);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glutPostRedisplay();
}

void update()
{
	// update your variables here

	square_pos += square_vel;
	square_age++;
	next_square++;
	if (next_square >= SQUARE_COUNT)
		next_square = 0;
	if (emitter_on)
	{
		//squares[next_square].init();
		if (square_age >= SQUARE_COUNT)
		{
			// restart square movement
			square_age = 0.0;
			square_pos.set(0.0, 0.0);

		}
	}
	if (speed_decrease)
	{
		sleep(0.20 / 60.0);
	}
	else if (speed_increase)
	{
		sleep(0.10 / 60.0);
	}

	if (anti_clockwise)
	{
		Vector2 square_vel1(5.0, 2.0);
	}
	else if (clockwise)
	{
		Vector2 square_vel2(5.0, -5.0);
	}
	else
		Vector2 square_vel3(5.0, 0.0);
	glutPostRedisplay();

};

void display(void)
{
	
		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// clear the screen - any drawing before here will not display
		glPushMatrix();
		glTranslated(square_pos.x, square_pos.y, 0.0f);

		// draw a white square
		if (red_color_increase)
		{
			glColor3d(255, 0, 0);
		}

		else if (green_color_increase)
		{
			glColor3d(0, 255, 0);
		}
		else if (blue_color_increase)
		{
			glColor3d(0, 0, 255);
		}


		else if (white_color_increase) {
			glColor3d(0.25, 0.25, 0.25);
		}
		else
			glColor3d(255, 255, 255);


		glBegin(GL_POLYGON);
		glVertex2f(-5.0, -5.0);
		glVertex2f(-5.0, 5.0);
		glVertex2f(5.0, 5.0);
		glVertex2f(5.0, -5.0);

		glEnd();





		glPopMatrix();

		// send the current image to the screen - any drawing after here will not display
		glutSwapBuffers();
	
	
};





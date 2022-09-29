#pragma once
#include "ObjLibrary/Vector2.h"
#include "GetGlut.h"
#include "Sleep.h"
using namespace ObjLibrary;

Vector2 square_pos(0.0, 0.0);
Vector2 square_vel(5.0, 0.0);
Vector2 square_vel1(5.0, 2.0);
double square_age = 0.0;
void draw();

class Square
{
	
public:
	// declare your constructor here
	Vector2 pos;
	Vector2 vel;
	double age = 0.0;


	void init();

	bool isAlive()
	{
		if (age <= 60)
			return true;
		else
			return false;
	};
	

	/*void init()
	{
		pos.set(0.0, 0.0);
		vel.set(5.0, 1.0);
		age = 0;
	}*/


	// declare your public member functions here
	void update()
	{
		// update your variables here
		pos += vel;
		age++;
		
		/*if (age > 60)
		{
			// restart square movement
			age = 0.0;
			pos.set(0.0, 0.0);
		}*/
		sleep(1.0 / 60.0);
		glutPostRedisplay();
	};

	void draw()
	{
		if (isAlive())
		{
			// draw square here
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			// clear the screen - any drawing before here will not display
			glPushMatrix();
			glTranslated(pos.x, pos.y, 0.0f);

			// draw a white square
			glColor3d(1.0, 1.0, 1.0);
			glBegin(GL_POLYGON);
			glVertex2f(-50.0, -50.0);
			glVertex2f(-50.0, 50.0);
			glVertex2f(50.0, 50.0);
			glVertex2f(50.0, -50.0);

			glEnd();

			glPopMatrix();

			// send the current image to the screen - any drawing after here will not display
			glutSwapBuffers();
		}
		
		
	};


private:
	// declare your private member functions here

	// declare your member variables here
};


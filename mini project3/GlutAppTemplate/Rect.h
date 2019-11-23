#ifndef Rect_h
#define Rect_h
#define _USE_MATH_DEFINES
#include <math.h>

struct Rect
{
	float cornerX;
	float cornerY;
	float width;
	float height;
	float centerX;
	float centerY;
	float red, green, blue;
	bool select;
	bool X;
	bool O;

	Rect()
	{
		cornerX = 0;
		cornerY = 0;
		width = 0;
		height = 0;
		red = 1;
		green = 1;
		blue = 1;
		select = false;
	}

	Rect(float cornerX,float cornerY,float width,float height)
	{
		this->cornerX = cornerX;
		this->cornerY = cornerY;
		this->width = width;
		this->height = height;
		red = 1;
		green = 1;
		blue = 1;
		select = false;
		centerX = cornerX + (width/2);
		centerY = cornerY - (width/2);
	}

	Rect(float cornerX,float cornerY,float width,float height,float red,float green,float blue)
	{
		this->cornerX = cornerX;
		this->cornerY = cornerY;
		this->width = width;
		this->height = height;
		this->red = red;
		this->green = green;
		this->blue = blue;
		select = false;
		centerX = cornerX + (width/2);
		centerY = cornerY - (width/2);
	}

	bool contains(float x, float y)
	{
		return (((cornerX <= x) && (x <= (cornerX + width))) && ((cornerY >= y) && (y >= (cornerY - height))));
	}

	void drawTicTac()
	{
		if(X == true)
		{
			//	set color to yellow
			glColor3f(1,1,0);

			//	draw one rect of X
			glBegin(GL_POLYGON);
			glVertex2f(cornerX + 0.111, cornerY);
			glVertex2f(cornerX + width, cornerY - 0.555);
			glVertex2f(cornerX + 0.555, cornerY - height);
			glVertex2f(cornerX, cornerY - 0.111);
			glEnd();

			//	draw other rect of X
			glBegin(GL_POLYGON);
			glVertex2f(cornerX + 0.555, cornerY);
			glVertex2f(cornerX + width, cornerY - 0.111);
			glVertex2f(cornerX + 0.111, cornerY - height);
			glVertex2f(cornerX, cornerY - 0.555);
			glEnd();

			//	white background square
			glColor3f(1,1,1);
			glBegin(GL_POLYGON);
			glVertex2f(cornerX,cornerY);
			glVertex2f(cornerX+width,cornerY);
			glVertex2f(cornerX+width,cornerY-height);
			glVertex2f(cornerX,cornerY-height);
			glEnd();
		}
		else if(O == true)
		{

			// white circle inside blue circle
			glColor3f(1,1,1);
			glBegin(GL_POLYGON);
			for(int i = 0; i < 1000; i++)
			{
				float theta = 2.0 * M_PI * i / 1000;
				glVertex2f(0.2 * cos(theta) + centerX, 0.2 * sin(theta) + centerY);
			}
			glEnd();

			// blue circle
			glColor3f(0,1,1);
			glBegin(GL_POLYGON);
			for(int i = 0; i < 1000; i++)
			{
				float theta = 2.0 * M_PI * i / 1000;
				glVertex2f(0.32 * cos(theta) + centerX, 0.32 * sin(theta) + centerY);
			}
			glEnd();

			// white background of square
			glColor3f(1,1,1);
			glBegin(GL_POLYGON);
			glVertex2f(cornerX,cornerY);
			glVertex2f(cornerX+width,cornerY);
			glVertex2f(cornerX+width,cornerY-height);
			glVertex2f(cornerX,cornerY-height);
			glEnd();
		}
		else
		{
			//	white square
			glColor3f(1,1,1);
			glBegin(GL_POLYGON);
			glVertex2f(cornerX,cornerY);
			glVertex2f(cornerX+width,cornerY);
			glVertex2f(cornerX+width,cornerY-height);
			glVertex2f(cornerX,cornerY-height);
			glEnd();
		}
	}

	void draw()
	{
		glColor3f(red,green,blue);
		glBegin(GL_POLYGON);
		glVertex2f(cornerX,cornerY);
		glVertex2f(cornerX+width,cornerY);
		glVertex2f(cornerX+width,cornerY-height);
		glVertex2f(cornerX,cornerY-height);
		glEnd();
	}
};

#endif

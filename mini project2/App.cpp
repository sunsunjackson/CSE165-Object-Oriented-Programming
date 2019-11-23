#include "App.h"
#include "Rect.h"
#include <deque>


deque<Rect> z;

App::App(const char* label, int x, int y, int w, int h) : GlutApp(label, x, y, w, h) {
	// Initialize state variables
	mx = 0.0;
	my = 0.0;
}

void App::draw() {

	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Set background color
	glClearColor(1.0, 1.0, 0.0, 1.0);

	// Set up the transformations stack
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	// Draw a white cross
	glColor3d(1.0, 1.0, 1.0);

	glBegin(GL_LINES);

	glVertex2f(mx - 0.05f, my);
	glVertex2f(mx + 0.05f, my);

	glVertex2f(mx, my - 0.05f);
	glVertex2f(mx, my + 0.05f);

	glEnd();

	//Create the rectangles
	Rect a(0.1f, 0.5f, 0.5f, 0.5f);
	Rect b(0.2f, 0.4f, 0.5f, 0.5f);
	Rect c(0.2f, -0.2f, 0.2f, 0.2f);
	Rect d(-0.9f, -0.3f, 0.6f, 0.6f);
	
	//Push back
	z.push_back(a);
	z.push_back(b);
	z.push_back(c);
	z.push_back(d);

	//Color of the rectangles
	bool color = false;
	for (int a = 0; a < z.size(); a++) {
		glColor3d(1.0, 0.0, 0.0);
		

		//color the rectangles after it is clicked
		if (z[a].contains(mx, my) && color == false) {
			color = true;
			glColor3d(0.0, 0.0, 1.0);
		}

		//Formula for the click
		glBegin(GL_POLYGON);
		glVertex2f(z[a].x, z[a].y);
		glVertex2f(z[a].x, z[a].y - z[a].length);
		glVertex2f(z[a].x + z[a].width, z[a].y - z[a].length);
		glVertex2f(z[a].x + z[a].width, z[a].y);
		glEnd();

	}

	// We have been drawing everything to the back buffer
	// Swap the buffers to see the result of what we drew
	glFlush();
	glutSwapBuffers();
}

void App::mouseDown(float x, float y) {
	// Update app state
	mx = x;
	my = y;

	//Moving on to the next rectangle
	for (int i = 0; i < z.size(); i++) {
		if (z[i].contains(mx, my)) {
			z.push_front(z[i]);
			z.erase(z.begin() + i + 1); 
		}
	}

	// Redraw the scene
	redraw();
}

void App::mouseDrag(float x, float y) {
	// Update app state
	mx = x;
	my = y;

	// Redraw the scene
	redraw();
}

void App::keyPress(unsigned char key) {
	if (key == 27) {
		// Exit the app when Esc key is pressed
		exit(0);
	}
}


//I worked together/collaborated with Zhuohong Chen and Guangyu Li for this project
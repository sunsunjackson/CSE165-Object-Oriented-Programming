#include "App.h"
#include "Rect.h"
#include <deque>
#include <ctime>
#include <cstdlib>

using namespace std;

float side = 0.665;

// Lines when winning
Rect *topleft = new Rect(-1, 1, side, side);
Rect *topmid = new Rect(-0.333, 1, side, side);
Rect *topright = new Rect(0.333, 1, side, side);
Rect *midleft = new Rect(-1, 0.333, side, side);
Rect *middle = new Rect(-0.333, 0.333, side, side);
Rect *midright = new Rect(0.333, 0.333, side, side);
Rect *botleft = new Rect(-1, -0.333, side, side);
Rect *botmid = new Rect(-0.333, -0.333, side, side);
Rect *botright = new Rect(0.333, -0.333, side, side);

Rect *horizontalbot = new Rect(-0.888,-0.640,1.8,0.05,1,1,1);
Rect *horizontalmid = new Rect(-0.888,0.028,1.8,0.05,1,1,1);
Rect *horizontaltop = new Rect(-0.888,0.699,1.8,0.05,1,1,1);

Rect *verticalleft = new Rect(-0.699,0.888,0.05,1.8,1,1,1);
Rect *verticalmid = new Rect(-0.028,0.888,0.05,1.8,1,1,1);
Rect *verticalright = new Rect(0.640,0.888,0.05,1.8,1,1,1);

Rect *blackback = new Rect(-1,1,2,2,0,0,0);

std::deque<Rect*> rects;

bool Xturn;
bool win;
bool AIsel;
bool AI;
bool winX;
bool winO;
bool gamedraw;
int boxCount;
int winCase;

// Initialize App.cpp
App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h)
{
	// Initialize state variables
	mx = 0.0;
	my = 0.0;

	rects.push_front(topleft);
	rects.push_front(topmid);
	rects.push_front(topright);

	rects.push_front(midleft);
	rects.push_front(middle);
	rects.push_front(midright);

	rects.push_front(botleft);
	rects.push_front(botmid);
	rects.push_front(botright);

	cout << "Key 1 to play with AI" << endl;
	cout << "key 2 for 2 players" << endl;
}

int App::randNum()
{
	int x = rand() % 8;
	//cout << "RANDOM is " << x << endl;
	return x;
}

void App::resetGame()
{
	Xturn = true;
	win = false;
	winX = false;
	winO = false;
	gamedraw = false;
	winCase = 0;
	boxCount = 0;
	for(int i = 0; i < rects.size(); i++)
	{
		rects.at(i)->X = false;
		rects.at(i)->O = false;
		rects.at(i)->select = false;
	}
}

//	botright 0, botmid 1, botleft 2, midright 3, middle 4, midleft 5, topright 6, topmid 7, topleft 8
//	possible wins: 012 345 678 036 147 258 246 048 

bool App::checkWinner()
{
	if(boxCount >= 3 && (winX == false && winO == false))
	{
		if(rects.at(0)->X == true && rects.at(1)->X == true && rects.at(2)->X == true)
		{
			//X is winner
			cout << "X wins" << endl;
			winX = true;
			winCase = 1;
			return true;
		}
		else if(rects.at(3)->X == true && rects.at(4)->X == true && rects.at(5)->X == true)
		{
			//X is winner
			cout << "X wins" << endl;
			winX = true;
			winCase = 2;
			return true;
		}
		else if(rects.at(6)->X == true && rects.at(7)->X == true && rects.at(8)->X == true)
		{
			//X is winner
			cout << "X wins" << endl;
			winX = true;
			winCase = 3;
			return true;
		}
		else if(rects.at(0)->X == true && rects.at(3)->X == true && rects.at(6)->X == true)
		{
			//X is winner
			cout << "X wins" << endl;
			winX = true;
			winCase = 4;
			return true;
		}
		else if(rects.at(1)->X == true && rects.at(4)->X == true && rects.at(7)->X == true)
		{
			//X is winner
			cout << "X wins" << endl;
			winX = true;
			winCase = 5;
			return true;
		}
		else if(rects.at(2)->X == true && rects.at(5)->X == true && rects.at(8)->X == true)
		{
			//X is winner
			cout << "X wins" << endl;
			winX = true;
			winCase = 6;
			return true;
		}
		else if(rects.at(2)->X == true && rects.at(4)->X == true && rects.at(6)->X == true)
		{
			//X is winner
			cout << "X wins" << endl;
			winX = true;
			winCase = 7;
			return true;
		}
		else if(rects.at(0)->X == true && rects.at(4)->X == true && rects.at(8)->X == true)
		{
			//X is winner
			cout << "X wins" << endl;
			winX = true;
			winCase = 8;
			return true;
		}
		else if(rects.at(0)->O == true && rects.at(1)->O == true && rects.at(2)->O == true)
		{
			//O is winner
			cout << "O wins" << endl;
			winO = true;
			winCase = 1;
			return true;
		}
		else if(rects.at(3)->O == true && rects.at(4)->O == true && rects.at(5)->O == true)
		{
			//O is winner
			cout << "O wins" << endl;
			winO = true;
			winCase = 2;
			return true;
		}
		else if(rects.at(6)->O == true && rects.at(7)->O == true && rects.at(8)->O == true)
		{
			//O is winner
			cout << "O wins" << endl;
			winO = true;
			winCase = 3;
			return true;
		}
		else if(rects.at(0)->O == true && rects.at(3)->O == true && rects.at(6)->O == true)
		{
			//O is winner
			cout << "O wins" << endl;
			winO = true;
			winCase = 4;
			return true;
		}
		else if(rects.at(1)->O == true && rects.at(4)->O == true && rects.at(7)->O == true)
		{
			//O is winner
			cout << "O wins" << endl;
			winO = true;
			winCase = 5;
			return true;
		}
		else if(rects.at(2)->O == true && rects.at(5)->O == true && rects.at(8)->O == true)
		{
			//O is winner
			cout << "O wins" << endl;
			winO = true;
			winCase = 6;
			return true;
		}
		else if(rects.at(2)->O == true && rects.at(4)->O == true && rects.at(6)->O == true)
		{
			//O is winner
			cout << "O wins" << endl;
			winO = true;
			winCase = 7;
			return true;
		}
		else if(rects.at(0)->O == true && rects.at(4)->O == true && rects.at(8)->O == true)
		{
			//O is winner
			cout << "O wins" << endl;
			winO = true;
			winCase = 8;
			return true;
		}
		else if(boxCount == 9)
		{
			//game is a draw
			cout << "Draw" << endl;
			gamedraw = true;
			return true;
		}
	}
	return false;
}

void App::draw()
{
	//	Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//	Set background color to white
	glClearColor(0.0, 0.0, 0.0, 1.0);

   //	Set up the transformations stack
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if(win == true)
	{
		if(winCase == 1)
		{
			horizontalbot->draw();
		}
		else if(winCase == 2)
		{
			horizontalmid->draw();
		}
		else if(winCase == 3)
		{
			horizontaltop->draw();
		}
		else if(winCase == 4)
		{
			verticalright->draw();
		}
		else if(winCase == 5)
		{
			verticalmid->draw();
		}
		else if(winCase == 6)
		{
			verticalleft->draw();
		}
		else if(winCase == 7)
		{
			glColor3f(0,0,0);
			glBegin(GL_POLYGON);
			glVertex2f(-0.9,-0.88);
			glVertex2f(-0.88,-0.9);
			glVertex2f(0.9,0.88);
			glVertex2f(0.88,0.9);
			glEnd();
		}
		else if(winCase == 8)
		{
			glColor3f(0, 0, 0);
			glBegin(GL_POLYGON);
			glVertex2f(-0.9,0.88);
			glVertex2f(-0.88,0.9);
			glVertex2f(0.9,-0.88);
			glVertex2f(0.88,-0.9);
			glEnd();
		}
		
		//print out line and board state
		for(int i = 0; i < rects.size(); i++)
		{
			rects.at(i)->drawTicTac();
		}
	}
	else
	{
		if(AIsel == false)
		{
			blackback->draw();
		}
		else
		{
			for(int i = 0; i < rects.size(); i++)
			{
				rects.at(i)->drawTicTac();
			}
			win = checkWinner();
			if(win == false && AI == true && Xturn == false && winX == false && winO == false)
			{
				//cout << "AI turn" << endl;
				srand(time(NULL));
				while(true)
				{
					int j = randNum();
					if(rects.at(j)->select == false)
					{
						rects.at(j)->O = true;
						rects.at(j)->select = true;
						Xturn = true;
						boxCount++;
						break;
					}
				}
				redraw();
			}
			else
			{
				redraw();
			}
		}
	}
	// We have been drawing everything to the back buffer
	// Swap the buffers to see the result of what we drew
	glFlush();
	glutSwapBuffers();
}



void App::tictacSelect(float x, float y)
{
	if(AI == false)
	{
		for(int i = 0; i < rects.size(); i++)
		{
			if(rects.at(i)->contains(x,y) && Xturn == true && rects.at(i)->select == false)
			{
				rects.at(i)->X = true;
				rects.at(i)->select = true;
				Xturn = false;
				boxCount++;
			}
			else if(rects.at(i)->contains(x,y) && Xturn == false && rects.at(i)->select == false)
			{
				rects.at(i)->O = true;
				rects.at(i)->select = true;
				Xturn = true;
				boxCount++;
			}
		}
	}
	else
	{
		for(int i = 0; i < rects.size(); i++)
		{
			if(rects.at(i)->contains(x,y) && Xturn == true && rects.at(i)->select == false)
			{
				rects.at(i)->X = true;
				rects.at(i)->select = true;
				Xturn = false;
				boxCount++;
			}
		}
	}
}

void App::mouseDown(float x, float y)
{
	// Update app state
	mx = x;
	my = y;

	if(AIsel == false)
	{
		//AIselect(mx,my);
	}
	else if(winX == false && winO == false)
	{
		tictacSelect(mx,my);
	}

	// Redraw the scene
	redraw();
}

void App::mouseDrag(float x, float y)
{
	// Update app state
	mx = x;
	my = y;

	// Redraw the scene
	redraw();
}

void App::keyPress(unsigned char key)
{
	switch (key)
	{
		case 27:
			exit(0);
			break;
		case '1':
			resetGame();
			cout << "AI mode!" << endl;
			AIsel = true;
			AI = true;
			redraw();
			break;
		case '2':
			resetGame();
			cout << "2P!" << endl;
			AIsel = true;
			AI = false;
			redraw();
			break;
	}
}

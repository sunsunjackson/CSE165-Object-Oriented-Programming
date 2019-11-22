#ifndef Rect_h
#define Rect_h

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include <iostream>

class Rect{
protected:
    
public:
    float speed;

    float x;
    float y;
    float w;
    float h;
    
    float r;
    float g;
    float b;
    
    Rect(float=0.0f, float=0.0f, float=0.4f, float=0.2f, float=1.0f, float=1.0f, float=1.0f);
    
    float getX() const;
    float getY() const;
    float getW() const;
    float getH() const;
    
    float getR() const;
    float getG() const;
    float getB() const;
    
    void setX(float);
    void setY(float);
    void setW(float);
    void setH(float);
    
    void setR(float);
    void setG(float);
    void setB(float);

    void moveRight();
    void moveLeft();

    void velocity();
    void jumpDOWN(float);
    
    
    
    bool contains(float, float) const;

    
    void redrawScene();
    
    virtual void draw() const;
    
    virtual ~Rect();

    bool contains(float a, float b) {
		if (a >= x && a <= x + w && b <= y && b >= y - h) {
            return true;
		}
		return false;

	}

};

#endif

#ifndef Circle_h
#define Circle_h
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

//source: Tom Mcgee helped me with the second constructor
class Circle {
    double x;
    double y;
    double r;

public:
    double area;
     //= 3.14159 * r * r;
    // double M_PI = 3.14159;

    // area = M_PI * r * r;

    Circle() {
      x = 0;
      y = 0;
      r = 1;  
      area = M_PI * r * r;
    }

    Circle(double xx, double yy, double rr) {
        x = xx;
        y = yy;
        r = rr;
        area = M_PI * r * r;
    }

    void setX(double xx) {
        x = xx;
    }
    
    
    double getX(){
        return x;
    }

    void setY(double yy) {
        y = yy;
    }
    double getY(){
        return y;
    }
    
    void setR(double rr) {
        r = rr;
        area = M_PI * r * r;
    }
    double getR(){
        return r;
    }
    
};

#endif
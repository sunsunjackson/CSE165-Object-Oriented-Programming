#ifndef Rect_h
#define Rect_h
#include "Vec.h"
using namespace std;

class Rect {
    private:
    float q, w, e, r;

    public:
    Rect() {
        q = 0.0;
        w = 0.0;
        e = 0.0;
        r = 0.0;
    }
    Rect(float q1, float w1, float e1, float r1)
    {
        //e = width, r = length
        q = q1;
        w = w1;
        e = e1;
        r = r1;
    }

bool contains(Vec vector) {
        if (vector.getX() >= q && vector.getX() <= q + e && vector.getY() >= w - r && vector.getY() <= w)
            return true;
        else
           return false;
    
    }

};
#endif
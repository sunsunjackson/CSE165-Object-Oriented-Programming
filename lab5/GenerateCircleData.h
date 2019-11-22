#ifndef GenerateCircleData_h
#define GenerateCircleData_h

#include "Vec.h"
#include <math.h>
#include <vector>
using namespace std;

void generateCircleData(vector<Vec*>& points, const Vec& center, float radius, int resolution){
    // Clear the points vector to make sure it's empty before you start
    points.clear();

    //Provide the rest of the code here...
    float x, y, degree;
    float theta = 2.0f * 3.1415926f/resolution;//get the current angle

    for(int i = 0; i < resolution; i++)
    {
        
        x = radius * cos(degree) + center.getX();//calculate the x component
        y = radius * sin(degree) + center.getY();//calculate the y component

        points.push_back(new Vec(x, y));

        degree += theta;
    }
    // for (double angle=0; angle<=2*3.1415926; angle+=0.001)//You are using radians so you will have to increase by a very small amount
    //  //This will have the coordinates  you want to draw a point at
    //  Vec(center.getX + radius*cos( angle ), center.getY + radius*sin( angle ) );
}

#endif
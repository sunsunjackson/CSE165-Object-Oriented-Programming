#include <iostream>

using namespace std;

struct Rect
{
	// Creating variables
	float x, y, width, length;

	//initialize the variables
	Rect() {
		x = 0.0;
		y = 0.0;
		width = 0.0;
		length = 0.0;
	}
	//Match the variables
	Rect(float a, float b, float width1, float length1) {
		x = a;
		y = b;
		width = width1;
		length = length1;
	}

	//Contains the variables
	bool contains(float a, float b) {
		if (a >= x && a <= x + width && b <= y && b >= y - length) {
			return true;
		}
		return false;

	}
};
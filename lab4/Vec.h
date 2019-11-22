#ifndef Vec_h
#define Vec_h
using namespace std;

class Vec {
    private:
    float x, y;

    public:
    //Default Constructor
    Vec() {
        x = 0.0;
        y = 0.0;
    }
    Vec(float x1, float y1)
    {
        x = x1;
        y = y1;
    }
    float getX()
    {
        return x;
    }
    float getY()
    {
        return y;
    }
    void add (Vec v)
    {
        x=x + v.x;
        y=y + v.y;   
    }
    
    void print ()  {
        cout << "("<< x << "," << y<< ")"<< endl;
    }
};

#endif
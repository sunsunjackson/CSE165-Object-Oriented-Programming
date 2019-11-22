#ifndef Circle_h
#define Circle_h

#include "Sortable.h"

class Circle : public Sortable
{
    
public:
    double r;
    
    int pi = 3.1415;
    Circle(){
        r = NULL;
    }
    
    Circle(double radius){
        r = radius;
    }
    
    virtual bool compare(const Sortable*s){
        
        return this->compareCircles((Circle*)(s));
    }
    
    bool compareCircles(const Circle*s){
        if(this->r < s->r){
            return true;
        }
        return false;
    }
    
    
    virtual void print(){
        cout << "Circle with radius: " << r << endl;
    }
    
};


#endif /* Circle_h */
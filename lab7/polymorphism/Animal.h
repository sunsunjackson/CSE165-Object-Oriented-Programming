#ifndef LA5_Animal_h
#define LA5_Animal_h

// #include "Cat.h"
// #include "Dog.h"
#include <iostream>

using namespace std;

class Animal {
    string name;
    int age;
    
public:
    
    //default constructor
    Animal(){
        name = "Generic Name";
        age = 0;
    }
    
    //constructor
    Animal(string n, int a){
        name = n;
        age = a;
    }
    
    virtual void talk(){
      cout << " " << endl;
    }

};

#endif

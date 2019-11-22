#ifndef Dog_h
#define Dog_h

#include <iostream>
#include <string>
#include <vector>
#include "Animal.h"

using namespace std;

class Dog : public Animal {
    string name;
    int age;
    
    public:
    
    Dog(){
        cout << "Creating Generic Animal" << endl;
        name = "Generic Animal";
        age = 0;
    }
    
    Dog(string name1, int age1){
        name = name1;
        age = age1;
        cout << "Creating dog" << endl;
    }
    void display (const vector<Dog*> & list){
        
    }
    
    string getName(){
        return name;
    }
    
    void setName(string name){
        this->name = name;
    }
    
    int getAge(){
        return age;
    }
    
    void setAge(int age){
        this->age = age;
    }
    
    ~Dog(){
        cout << "Deleting Dog" << endl;
    }
    
    void feed(){
        cout << "A bone, please!" << endl;
    }

};
#endif
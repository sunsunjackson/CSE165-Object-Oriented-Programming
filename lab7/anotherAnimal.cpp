#include <iostream>
#include <vector>
#include "Animal.h"
#include "Dog.h"
#include "display.h"

using namespace std;

class anotherAnimal : public Animal {
    string name;
    int age;

public:
    anotherAnimal(string name, int age){
        this->name = name;
        this->age = age;

        setName(name);
        setAge(age);
    }
};

int main() {
    int N;
    char char1;
    string name;
    int age;

    cin >> N;

    vector<Animal*> vector;

    for(int i = 1; i <= N; i++) {
        cin >> char1 >> name >> age;
        if(char1 == 'A') {
            vector.push_back(new anotherAnimal(name, age));
        }
        else if(char1 == 'D') {
            vector.push_back(new Dog(name, age));
        }
        

    }

    display(vector);

    return 0;
}
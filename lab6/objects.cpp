#include <iostream>
#include "Object.h"

using namespace std;

int Object::count = 0;

 //calling copy constructor
Object f(Object someObject){
    return someObject;
}

int main(int argc, const char * argv[])
{

    Object myObject;
    
    Object another;
    
    cout << another.count << endl;
    return 0;
}

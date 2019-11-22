#ifndef Object_h
#define Object_h
//It instantiates some Objects and prints out the value of the count variable, 
//which simply keeps track of how many instances of Object have been created.
//Your task is to implement the Object class. It only needs to have a static member named count,
//which should be incremented each time a new instance of the class is created. You should also provide the appropriate constructors. 
//Do not worry about destructors for this exercise. Save your class in a file named Object.h

class Object {
    int data;
    
public:
    static int count;
    Object() {
        data = 0;
        increment();
        //count++;
    }
    
    Object(int d) {
        data = d;
        //count++;
    }


    //Copy constructor
    Object(const Object &f){
        data = f.data;
        increment();
    }

    //counting function
    void increment(void) {
        count ++;
    }

};

//int Generic::count = 0;

#endif
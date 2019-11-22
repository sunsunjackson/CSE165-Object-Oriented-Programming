#ifndef Generic_h
#define Generic_h
using namespace std;
//It instantiates some Generics and prints out the value of the count variable, 
//which simply keeps track of how many instances of Generic have been created.

class Generic {
    int data;
    
public:
    static int count;
    Generic() {
        data = 0;
        increment();
        //count++;
    }
    
    Generic(int d) {
        data = d;
        //count++;
    }

    //counting function
    void increment(void) {
        count ++;
    }

    // Generic(int count) {
    //     count = 2;
    // }
};

//initialize the ::
int Generic::count = 0;


#endif
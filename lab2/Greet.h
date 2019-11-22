#ifndef Greet_h
#define Greet_h
// We should include <string> here
#include <string>
using std::string;

// Implement your "greet" function below
void greet(string name, void (*func)(string)) {
    func(name); 
}

#endif /* Greet_h */
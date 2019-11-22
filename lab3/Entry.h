#ifndef Entry_h
#define Entry_h
#include <string>

using namespace std;

struct Entry {
    string name, Lastname, email;
    
    void setName(string firstname){
        name = firstname;
    }
    
    void setLastname(string last_name){
        Lastname=last_name;
    }
    
    void setEmail(string ur_email){
        email= ur_email;
    }
    
    void print (){
        cout << "First name: " << name << endl;
        cout << "Last name: " << Lastname<< endl;
        cout << "Email: " << email << endl;
        
    }
    
    

    
};


#endif 

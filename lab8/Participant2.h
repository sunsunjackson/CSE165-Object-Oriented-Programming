#ifndef Participant_h
#define Participant_h

#include "Sortable.h"

using namespace std;
class Participant : public Sortable
{
public:
    
    static bool (*comp_cb)(const Participant*, const Participant*);

    
    int age;
    string name;
    double score;
    
    Participant(){
        age = 0;
        name = "";
        score = 0;
    }
    
    Participant(string n, int a, double s)
    {
        age = a;
        name = n;
        score = s;
    }
    
    bool compare(const Sortable*s)
    {
        //Participant*p = (Participant*)s;
        //return this->compareParticipants((Participant*)(s));
        return !comp_cb(this, (Participant*)(s));

    }
    
    bool compareParticipants(Participant*p)
    {
        if(this->name < p->name && this->score == p->score && this->age == p->age){
            return true;
        }
        
        if(this->score > p->score){
            return true;
        }
        
        if(this->age < p->age && this->score == p->score){
            return true;
        }
    
        return false;
    }
    
    virtual void print()
    {
        cout << this->name <<  "\t"  << this->age <<  "\t"  << this->score << endl;
    }
    
};


#endif /* Participant_h */
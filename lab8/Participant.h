#ifndef __PARTICIPANT_H__
#define __PARTICIPANT_H__
#include <iostream>
#include <iomanip>
#include "Sortable.h"
using namespace std;

class Participant : public Sortable
{
    string name;
    int age;
    double score;
    
public:
    Participant(const string name, int age, double score)
        : name(name), age(age), score(score)
    {
    }
    
    void print()
    {
        cout << name << "\t" << age << "\t" << setprecision(2) << score << endl;
    }
        
    bool compare(const Sortable *s)
    {
        const Participant *other = dynamic_cast<const Participant *>(s);
        if(other)
        {
            if(score == other->score)
            {
                if(age == other->age)
                {
                    return name.compare(other->name) < 0;
                }
                else return age < other->age;
            }
            else return score > other->score;
        }
        
        return false;
    }
};

#endif
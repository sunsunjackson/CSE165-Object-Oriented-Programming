#ifndef Data_h
#define Data_h


#include <iostream>
#include <vector>
using namespace std;

class Data{
    
public:
    vector<int>vec;

//add method
    Data() {
    }
    ~Data() {
    }
    void add(int num) {
        vec.push_back(num);
    }
    
    bool compare(int num)
    {
        return NULL;
    }

//print method   
    void print() {
        for(int i = 0; i < vec.size(); i++){
            cout << vec[i] << " " << endl;

        }
    }

//Sort   
    void sort()
    {
        int num2 = vec.size();
        int temp;

        for(int i = 1;i < num2; i++)
        {
            for(int j=  0; j < (num2 - i); j++)
                if(vec[j] > vec[j + 1])
                {
                    temp = vec[j];
                    vec[j] = vec[j + 1];
                    vec[j + 1] = temp;
                }
        }
    }
};

#endif
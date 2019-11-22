#ifndef Data_h
#define Data_h

using namespace std;
#include <vector>
#include <climits>
#include "Sortable.h"

class Data : public Sortable {
public:
	vector<Sortable*>v;

	void add(Sortable*s){
		v.push_back(s);
	}

	bool compare(const Sortable*s){}

	void print()
	{
		for (int i = 0; i < v.size(); i++) {
			v[i]->print();
		}
		cout << endl;

	}

	//Bubble sort weeee

	void sort()
	{
		int n = v.size();
		Sortable*temp;
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (v[j + 1]->compare(v[j])) {
					temp = v[j];
					v[j] = v[j + 1];
					v[j + 1] = temp;
				}
			}
		}
	}
};

#endif /* Data_h */
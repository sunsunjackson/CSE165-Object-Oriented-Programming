// Primeing.cpp : Defines the entry point for the console application.
//


#include <iostream>

using namespace std;


int main() {

	int a;

	cin >> a;

	for (int b = 2; b < a; b++)
	{
		bool prime = true;

		for (int c = 2; c*c <= b; c++)
		{
			if (b % c == 0)
			{
				prime = false;
				break;
			}
		}
		if (prime) cout << b << endl;
	}
	return 0;
}





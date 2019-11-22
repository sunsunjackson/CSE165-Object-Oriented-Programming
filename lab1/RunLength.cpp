// RunLength.cpp : Defines the entry point for the console application.
//


#include <iostream>

using namespace std;

int main()
{
	int a;
	char b;

	while (true) {
		cin >> b;
		cin >> a;

		if (a == -2) {
			break;
		}
		else if (a == -1) {
			cout << endl;
		}
		else {
			for (int c = a; c > 0; c--) {
				cout << b;
			}
		}
	}









    return 0;
}


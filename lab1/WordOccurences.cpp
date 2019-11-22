#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

string RemovePunct(string & word) {
	char exc = '!';
	char comma = ',';
	char period = '.';
	char question = '?';
	for (int i = 0; i < word.length(); i++) {
		if (word[i] == exc) {
			word.pop_back();
		}
		else if (word[i] == comma) {
			word.pop_back();
		}
		else if (word[i] == period) {
			word.pop_back();
		}
		else if (word[i] == question) {
			word.pop_back();
		}
	}
	return word;
}

string ToLowercase(string & word) {

	std::transform(word.begin(), word.end(), word.begin(), ::tolower);

	return word;
}

int main() {
	string wo;
	cin >> wo;
	std::transform(wo.begin(), wo.end(), wo.begin(), ::tolower);

	ifstream in("words.txt");

	int wordcount = 0;

	string word;

	while (in >> word) {
		RemovePunct(word);
		ToLowercase(word);

		if (word == wo) {
			++wordcount;
		}
	}
	cout << wordcount << endl;
}

/*
string lastLetters(string word) {
	int last = word.length() - 1;
	int slast = word.length() - 2;
	cout << slast << endl;
	cout << last << endl;
	string wordmod;
	string l1;
	string l2;
	if (word.length() >= 2) {
		l1 = word[last];
		l2 = word[slast];
		wordmod = l2 + " " + l1;
		cout << wordmod << endl;
		word.erase();
		word.append(l2);
		word.append(" ");
		word.append(l1);
		cout << word << endl;
	}
	// else if (word.length() < 2) {
	//   wordmod = word[count];
	//}
	word = wordmod;
	return wordmod;
}

int main() {
	string word = "apple";
	lastLetters(word);
	system("Pause");
} */

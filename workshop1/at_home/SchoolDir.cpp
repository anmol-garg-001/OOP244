//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name : Anmol Garg
// Student ID: 149916199
// Student email: agarg15@myseneca.ca
// Date : 27 Sept, 2020

#include <iostream>
#include "School.h"
using namespace std;
using namespace sdds;

void flushkeys();
bool yes();

int main() {
	bool done = false;
	char schoolCode[6];
	loadSchools();
	cout << "Seneca School Extension search." << endl << endl;
	while (!done) {
		cout << "Enter the School code: ";
		cin >> schoolCode;
		flushkeys();
		displaySchoolExtension(schoolCode);
		cout << "Do another search? (Y)es: ";
		done = !yes();
		cout << endl;
	}
	cout << "Goodbye!" << endl;
	return 0;
}

// flushes the keyboard
void flushkeys() {
	while (cin.get() != '\n');
}

// returns true if user enter y or Y
bool yes() {
	char ch = cin.get();
	flushkeys();
	return ch == 'y' || ch == 'Y';
}
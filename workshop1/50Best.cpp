//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
// Name : Anmol Garg
// Student ID: 149916199
// Student email: agarg15@myseneca.ca
// Date : 22 Sept, 2020

#include <iostream>
#include "Movie.h"
using namespace std;
using namespace sdds;

void flushkeys();
bool yes();

int main() {
	bool done = false;
	char genre[128];
	loadMovies();
	cout << "Welcome to 50 top movies of all times \"genre\" search." << endl << endl;
	while (!done) {
		cout << "Enter the movie genre to start the search: ";
		cin >> genre;
		flushkeys();
		displayMoviesWithGenre(genre);
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
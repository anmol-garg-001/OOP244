//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshops and assignments.
// Name : Anmol Garg
// Student ID: 149916199
// Student email: agarg15@myseneca.ca
// Date : 27 Sept, 2020

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "File.h"

using namespace std;

namespace sdds {
	FILE* fptr;

	// opens the data file and returns true is successful
	bool openFile(const char filename[]) {
		fptr = fopen(filename, "r");
		return fptr != NULL;
	}

	// closes the data file
	void closeFile() {
		if (fptr) fclose(fptr);
	}

	// reads the school code of the school from the global fptr File pointer
	// returns true if successful
	bool readCode(char code[]) {
		return fscanf(fptr, "%[^ ] ", code) == 1;
	}

	// reads the extension of the school code from the global fptr File pointer
	// returns true if successful
	bool readExtension(int* extension) {
		return fscanf(fptr, "%d\n", extension) == 1;
	}
}
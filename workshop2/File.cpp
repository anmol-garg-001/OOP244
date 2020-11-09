//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshops and assignments.
// Name : Anmol Garg
// Student ID: 149916199
// Student email: agarg15@myseneca.ca
// Date : 30 Sept, 2020

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
	FILE* fptr;
	bool openFile(const char filename[]) {
		fptr = fopen(filename, "r");
		return fptr != NULL;
	}
	int noOfRecords() {
		int noOfRecs = 0;
		char ch;
		while (fscanf(fptr, "%c", &ch) == 1) {
			noOfRecs += (ch == '\n');
		}
		rewind(fptr);
		return noOfRecs;
	}
	void closeFile() {
		if (fptr) fclose(fptr);
	}

	// TODO: read functions go here    
	bool read(char name[]) {
		return fscanf(fptr, "%[^,],", name) == 1;
	}

	bool read(int* studentNumber) {
		return fscanf(fptr, "%d,", studentNumber) == 1;
	}
	
	bool read(double* gpa) {
		return fscanf(fptr, "%lf\n", gpa) == 1;
	}
}
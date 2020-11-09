//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name : Anmol Garg
// Student ID: 149916199
// Student email: agarg15@myseneca.ca
// Date : 27 Sept, 2020

#include <iostream>
#include <cstring>
#include "School.h"
#include "File.h"

using namespace std;

namespace sdds {
	School schools[NUMSCHOOLS];

	// loads all the school codes and extensions into the global array of structures.
	bool loadSchools() {
		School sch;
		int snum = 0; // number of school codes read
		bool ok = true;
		if (openFile("schools.dat")) {
			while (ok && snum < NUMSCHOOLS) {
				ok = readCode(sch.schoolCode) && readExtension(&sch.extensionNumber);
				if (ok) schools[snum++] = sch;
			}
			closeFile();
		}
		return snum == NUMSCHOOLS;
	}

	// returns true is the school code matches with any of the records
	bool hasSchoolCode(const School* schp, const char schCode[]) {
		bool found = false;
		if (!strcmp(schp->schoolCode, schCode)) {
			found = true;
		}
		return found;
	}

	// displays the extension number associated with the school code
	void displaySchoolExtension(const char schoolCode[]) {
		int i;
		bool flag = true;
		for (i = 0; i < NUMSCHOOLS && flag; i++) {
			if (hasSchoolCode(&schools[i], schoolCode)) {
				cout << "416 491 5050 x " << schools[i].extensionNumber << endl;
				flag = false;
			}
		}
		if (flag == true) {
			cout << schoolCode << " School code not found!" << endl;
		}
	}
}
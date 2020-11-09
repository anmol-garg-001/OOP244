//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshops and assignments.
// Name : Anmol Garg
// Student ID: 149916199
// Student email: agarg15@myseneca.ca
// Date : 27 Sept, 2020

#ifndef SDDS_SCHOOL_H 
#define SDDS_SCHOOL_H

// Your header file content goes here
namespace sdds {
#define NUMSCHOOLS 24
	struct School {
		char schoolCode[6];
		int extensionNumber;
	};

	bool loadSchools();
	bool hasSchoolCode(const School* schp, const char schoolCode[]);
	void displaySchoolExtension(const char schoolCode[]);
}
#endif
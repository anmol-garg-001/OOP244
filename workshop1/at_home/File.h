//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshops and assignments.
// Name : Anmol Garg
// Student ID: 149916199
// Student email: agarg15@myseneca.ca
// Date : 27 Sept, 2020

#ifndef SDDS_FILE_H 
#define SDDS_FILE_H

// Your header file content goes here
namespace sdds {
	bool openFile(const char filename[]);
	void closeFile();
	bool readCode(char code[]);
	bool readExtension(int* extension);
}
#endif
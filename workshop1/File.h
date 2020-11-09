//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
// Name : Anmol Garg
// Student ID: 149916199
// Student email: agarg15@myseneca.ca
// Date : 22 Sept, 2020

#ifndef SDDS_FILE_H 
#define SDDS_FILE_H

// Your header file content goes here
namespace sdds {
	bool openFile(const char filename[]);
	void closeFile();
	bool readTitle(char title[]);
	bool readYear(int* year);
	bool readMovieRating(char rating[]);
	bool readDuration(int* duration);
	bool readGenres(char genres[][11]);
	bool readConsumerRating(float* rating);
}
#endif
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name : Anmol Garg
// Student ID: 149916199
// Student email: agarg15@myseneca.ca
// Date : 7 Oct, 2020

#ifndef _SDDS_SUBJECT_H_
#define _SDDS_SUBJECT_H_
namespace sdds {
	class Subject
	{
		char m_code[7]; // holds the subject code (exactly 6 characters)
		int m_mark;     // the mark out of 100
		char grade()const;
	public:
		void setEmpty();
		void set(const char* code, int mark);
		float scale4()const;
		bool isValid()const;
		void display()const;
	};
}
#endif // !_SDDS_SUBJECT_H_
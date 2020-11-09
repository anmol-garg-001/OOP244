//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshops and assignments.
// Name : Anmol Garg
// Student ID: 149916199
// Student email: agarg15@myseneca.ca
// Date : 11 Oct, 2020

#ifndef _SDDS_BAR_H_
#define _SDDS_BAR_H_
namespace sdds {
	class Bar {
		char m_title[20];
		char m_fill;
		int m_value;
	public:
		void setEmpty();
		void set(const char* title, char fill, int value);
		bool isValid()const;
		void draw()const;
	};
}
#endif // !_SDDS_BAR_H_
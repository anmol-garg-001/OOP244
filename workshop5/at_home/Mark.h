//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshops and assignments.
// Name : Anmol Garg
// Student ID: 149916199
// Student email: agarg15@myseneca.ca
// Date : 28 Oct, 2020

#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_
#include <iostream>

namespace sdds {
	class Mark {
		int m_mark;
		void setEmpty();
	public:
		Mark();
		Mark(int mark);
		operator int() const;
		operator double() const;
		operator char() const;
		operator bool() const;
		Mark& operator+=(const int& RightOperand);
		Mark& operator=(const int& RightOperand);
	};
	int operator+=(int& LeftOperand, const Mark& RightOperand);
}
#endif // SDDS_MARK_H_
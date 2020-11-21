//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name : Anmol Garg
// Student ID: 149916199
// Student email: agarg15@myseneca.ca
// Date : 18 November, 2020

#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include "LblShape.h"
namespace sdds {
	class Rectangle :public LblShape {
		int m_width;
		int m_height;
	public:
		Rectangle();
		Rectangle(const char* label, int width, int height);
		void getSpecs(std::istream& istr);
		void draw(std::ostream& os)const;
	};
}
#endif
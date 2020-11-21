//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name : Anmol Garg
// Student ID: 149916199
// Student email: agarg15@myseneca.ca
// Date : 18 November, 2020

#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include "LblShape.h"
namespace sdds {
   class Line: public LblShape{
	   int m_length;
   public:
	   Line();
	   Line(const char* label, int length);
	   void getSpecs(std::istream& istr);
	   void draw(std::ostream& os)const;
   };
}
#endif // !SDDS_LINE_H


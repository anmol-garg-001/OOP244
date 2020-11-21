//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name : Anmol Garg
// Student ID: 149916199
// Student email: agarg15@myseneca.ca
// Date : 18 November, 2020

#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include "Shape.h"
namespace sdds {
   class LblShape: public Shape{
	   char* m_label;
   protected:
	   const char* label() const;
   public:
	   LblShape();
	   LblShape(const LblShape& L) = delete;
	   LblShape& operator=(const LblShape& L) = delete;
	   LblShape(const char* label);
	   ~LblShape();
	   void getSpecs(std::istream& istr);
   };
}
#endif // !SDDS_LBLSHAPE_H



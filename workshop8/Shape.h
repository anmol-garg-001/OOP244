//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name : Anmol Garg
// Student ID: 149916199
// Student email: agarg15@myseneca.ca
// Date : 18 November, 2020

#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
#include <iostream>
namespace sdds {
   class Shape {
   public:
	   virtual void draw(std::ostream& os)const = 0;
	   virtual void getSpecs(std::istream& istr) = 0;
	   virtual ~Shape();
   };
   std::ostream& operator<<(std::ostream& os, const Shape& S);
   std::istream& operator>>(std::istream& istr, Shape& S);
}

#endif // !SDDS_SHAPE_H


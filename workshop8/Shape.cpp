//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name : Anmol Garg
// Student ID: 149916199
// Student email: agarg15@myseneca.ca
// Date : 18 November, 2020

#include "Shape.h"
namespace sdds {
    Shape::~Shape(){}
    std::ostream& operator<<(std::ostream& os, const Shape& S)
    {
        S.draw(os);
        return os;
    }
    std::istream& operator>>(std::istream& istr, Shape& S)
    {
        S.getSpecs(istr);
        return istr;
    }
}
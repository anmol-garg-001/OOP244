//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name : Anmol Garg
// Student ID: 149916199
// Student email: agarg15@myseneca.ca
// Date : 18 November, 2020

#include "Line.h"
using namespace std;
namespace sdds {
    Line::Line():LblShape()
    {
        m_length = 0;
    }
    Line::Line(const char* label, int length):LblShape(label)
    {
        m_length = length;
    }
    void Line::getSpecs(std::istream& istr)
    {
        LblShape::getSpecs(istr);
        istr >> m_length;
        istr.ignore(2000,'\n');
    }
    void Line::draw(std::ostream& os) const
    {
        if (m_length > 0 && LblShape::label() != nullptr)
        {
            os << LblShape::label() << endl;
            for (int i = 0; i < m_length; i++)
            {
                os << '=';
            }
        }
    }
}

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name : Anmol Garg
// Student ID: 149916199
// Student email: agarg15@myseneca.ca
// Date : 18 November, 2020
#include <cstring>
#include "Rectangle.h"
using namespace std;
namespace sdds {
	Rectangle::Rectangle() :LblShape()
	{
		m_width = 0;
		m_height = 0;
	}
	Rectangle::Rectangle(const char* label, int width, int height) :LblShape(label)
	{
		m_width = width;
		m_height = height;
		int label_length = strlen(LblShape::label());
		if (m_height < 3 || m_width < (label_length + 2))
		{
			m_height = -1;
			m_width = -1;
		}
	}
	void Rectangle::getSpecs(std::istream& istr)
	{
		LblShape::getSpecs(istr);
		istr >> m_width;
		istr.ignore();
		istr >> m_height;
		istr.ignore(1000,'\n');
	}
	void Rectangle::draw(std::ostream& os) const
	{
		if (m_height >= 0 && m_width >= 0)
		{
			int width = m_width - 2;
			os << '+';
			for (int i = 0; i < width; i++)
			{
				os << '-';
			}
			os << '+' << endl;
			os << '|';
			os.setf(ios::left);
			os.width(width);
			os << LblShape::label() << '|' << endl;
			os.unsetf(ios::left);
			for (int i = 0; i < m_height - 3; i++)
			{
				os << '|';
				for (int i = 0; i < width; i++)
				{
					os << ' ';
				}
				os << '|' << endl;
			}
			os << '+';
			for (int i = 0; i < width; i++)
			{
				os << '-';
			}
			os << '+';
		}
	}
}
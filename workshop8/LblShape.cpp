//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name : Anmol Garg
// Student ID: 149916199
// Student email: agarg15@myseneca.ca
// Date : 18 November, 2020

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "LblShape.h"
using namespace std;
namespace sdds {
	const char* LblShape::label() const
	{
		return m_label;
	}
	LblShape::LblShape()
	{
		m_label = nullptr;
	}
	LblShape::LblShape(const char* label)
	{
		m_label = new char[strlen(label) + 1];
		strcpy(m_label, label);
	}
	LblShape::~LblShape()
	{
		delete[] m_label;
	}
	void LblShape::getSpecs(std::istream& istr)
	{
		char label[21] = { '\0' };
		istr.get(label, 21, ',');
		delete[] m_label;
		m_label = new char[strlen(label) + 1];
		strcpy(m_label, label);
		istr.ignore(2000, ',');
	}
}
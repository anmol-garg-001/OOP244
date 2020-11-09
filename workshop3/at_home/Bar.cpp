//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshops and assignments.
// Name : Anmol Garg
// Student ID: 149916199
// Student email: agarg15@myseneca.ca
// Date : 11 Oct, 2020

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Bar.h"
using namespace std;

namespace sdds {
	void Bar::setEmpty()
	{
		m_value = -1;
		strcpy(m_title, "");
	}
	void Bar::set(const char* title, char fill, int value)
	{
		if (value < 0 || value >100)
		{
			setEmpty();
		}
		else
		{
			strcpy(m_title, title);
			m_fill = fill;
			m_value = value;
		}
	}
	bool Bar::isValid() const
	{
		bool valid = false;
		if (m_value > 0 && m_value < 100)
		{
			valid = true;
		}
		return valid;
	}
	void Bar::draw() const
	{
		int i = 0;
		if (Bar::isValid())
		{
			cout.width(20);
			cout.setf(ios::left);
			cout.fill('.');
			cout << m_title << "|";
			cout.unsetf(ios::left);
			for (i = 0; i < m_value/2; i++)
			{
				cout << m_fill;
			}
			cout << endl;
		}
	}
}
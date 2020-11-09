//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name : Anmol Garg
// Student ID: 149916199
// Student email: agarg15@myseneca.ca
// Date : 7 Oct, 2020

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Subject.h"
using namespace std;

namespace sdds {
	char Subject::grade() const
	{
		char grade = 'X';
		if (m_mark >= 0 && m_mark < 50)
		{
			grade = 'F';
		}
		else if(m_mark >= 50 && m_mark < 60)
		{
			grade = 'D';
		}
		else if (m_mark >= 60 && m_mark < 70)
		{
			grade = 'C';
		}
		else if (m_mark >= 70 && m_mark < 80)
		{
			grade = 'B';
		}
		else if (m_mark >= 80 && m_mark <= 100)
		{
			grade = 'A';
		}
		return grade;
	}
	void Subject::setEmpty()
	{
		m_mark = -1;
		strcpy(m_code, "");
	}
	void Subject::set(const char* code, int mark)
	{
		if (mark < 0 || mark > 100)
		{
			Subject::setEmpty();
		}
		else
		{
			m_mark = mark;
			strcpy(m_code, code);
		}
	}
	float Subject::scale4() const
	{
		float grade = 0.0f;
		if (m_mark >= 0 && m_mark < 50)
		{
			grade = 0.0f;
		}
		else if (m_mark >= 50 && m_mark < 60)
		{
			grade = 1.0f;
		}
		else if (m_mark >= 60 && m_mark < 70)
		{
			grade = 2.0f;
		}
		else if (m_mark >= 70 && m_mark < 80)
		{
			grade = 3.0f;
		}
		else if (m_mark >= 80 && m_mark <= 100)
		{
			grade = 4.0f;
		}
		return grade;
	}
	bool Subject::isValid() const
	{
		bool valid = false;
		if (m_mark >= 0)
		{
			valid = true;
		}
		return valid;
	}
	void Subject::display() const
	{
		if (Subject::isValid())
		{
			cout.width(15);
			cout.setf(ios::left);
			cout << m_code;
			cout.width(3);
			cout.setf(ios::right);
			cout << m_mark;
			cout.width(10);
			cout.setf(ios::fixed);
			cout.precision(1);
			cout << grade() << endl;
			cout.unsetf(ios::right);
		}
	}
}


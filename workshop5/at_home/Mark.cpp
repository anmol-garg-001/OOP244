//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshops and assignments.
// Name : Anmol Garg
// Student ID: 149916199
// Student email: agarg15@myseneca.ca
// Date : 28 Oct, 2020

#include "Mark.h"

namespace sdds {
	void Mark::setEmpty()
	{
		m_mark = -1;
	}
	Mark::Mark()
	{
		m_mark = 0;
	}
	Mark::Mark(int mark)
	{
		if (mark >= 0 && mark <= 100)
		{
			m_mark = mark;
		}
		else
		{
			setEmpty();
		}
	}
	Mark::operator int() const
	{
		int mark = 0;
		if (*this)
		{
			mark = m_mark;
		}
		return mark;
	}
	Mark::operator double() const
	{
		double gpa = 0.0;
		int mark = int(*this);

		if (mark >= 0 && mark < 50)
		{
			gpa = 0.0;
		}
		else if (mark >= 50 && mark < 60)
		{
			gpa = 1.0;
		}
		else if (mark >= 60 && mark < 70)
		{
			gpa = 2.0;
		}
		else if (mark >= 70 && mark < 80)
		{
			gpa = 3.0;
		}
		else if (mark >= 80 && mark <= 100)
		{
			gpa = 4.0;
		}

		return gpa;
	}
	Mark::operator char() const
	{
		char gradeLetter = 'X';
		int mark = int(*this);

		if (*this)
		{
			if (mark >= 0 && mark < 50)
			{
				gradeLetter = 'F';
			}
			else if (mark >= 50 && mark < 60)
			{
				gradeLetter = 'D';
			}
			else if (mark >= 60 && mark < 70)
			{
				gradeLetter = 'C';
			}
			else if (mark >= 70 && mark < 80)
			{
				gradeLetter = 'B';
			}
			else if (mark >= 80 && mark <= 100)
			{
				gradeLetter = 'A';
			}
		}
		return gradeLetter;
	}
	Mark::operator bool() const
	{
		bool valid = false;
		if (m_mark >= 0 && m_mark <= 100)
		{
			valid = true;
		}
		return valid;
	}
	Mark& Mark::operator+=(const int& RightOperand)
	{
		if (*this)
		{
			m_mark += RightOperand;
			if (!*this)
			{
				setEmpty();
			}
		}
		return *this;
	}
	Mark& Mark::operator=(const int& RightOperand)
	{
		m_mark = RightOperand;
		if (!*this)
		{
			setEmpty();
		}
		return *this;
	}
	int operator+=(int& LeftOperand, const Mark& RightOperand)
	{
		if (RightOperand)
		{
			LeftOperand += int(RightOperand);
		}
		return LeftOperand;
	}
}
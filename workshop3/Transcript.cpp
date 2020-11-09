//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name : Anmol Garg
// Student ID: 149916199
// Student email: agarg15@myseneca.ca
// Date : 7 Oct, 2020

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Transcript.h"
using namespace std;

namespace sdds {
	void Transcript::setEmpty()
	{
		m_studentName = nullptr;
		m_subjects = nullptr;
	}
	bool Transcript::isValid() const
	{
		bool valid = false, flag = true;
		int i = 0;

		if (m_studentName != nullptr && m_subjects != nullptr)
		{
			for (i = 0; i < m_noOfSubjects && flag; i++)
			{
				flag = m_subjects[i].Subject::isValid();
			}
			if (flag)
			{
				valid = true;
			}
		}

		return valid;
	}
	void Transcript::Title() const
	{
		cout << m_studentName << endl;
		cout << "-----------------------------" << endl;
	}
	float Transcript::gpa() const
	{
		int i;
		float gpa = 0.0f, avg = 0.0f;
		for (i = 0; i < m_noOfSubjects; i++)
		{
			avg += m_subjects[i].Subject::scale4();
		}
		gpa = avg / m_noOfSubjects;
		return gpa;
	}
	void Transcript::footer() const
	{
		cout << "-----------------------------" << endl;
		cout.width(26);
		cout.setf(ios::right);
		cout << "GPA: " << gpa() << endl;
		cout.unsetf(ios::right);
	}
	void Transcript::init(const char* studentName, int noOfSubjects)
	{
		int i;
		if (studentName == NULL || noOfSubjects < 1)
		{
			Transcript::setEmpty();
		}
		else
		{
			m_noOfSubjects = noOfSubjects;
			m_subjectsAdded = 0;
			m_studentName = new char[strlen(studentName) + 1];
			strcpy(m_studentName, studentName);
			m_subjects = new Subject[m_noOfSubjects];
			for (i = 0; i < noOfSubjects; i++)
			{
				m_subjects[i].Subject::setEmpty();
			}
		}
	}
	bool Transcript::add(const char* subject_code, int mark)
	{
		int i;
		bool isAdded = false, flag = true;
		if (m_subjectsAdded < m_noOfSubjects)
		{
			for (i = 0; i < m_noOfSubjects && flag; i++)
			{
				if (!m_subjects[i].Subject::isValid())
				{
					m_subjects[i].set(subject_code, mark);
					flag = false;
				}
			}
			m_subjectsAdded++;
			isAdded = true;
		}
		return isAdded;
	}
	void Transcript::display() const
	{
		int i = 0;
		if (Transcript::isValid())
		{
			Title();
			for (i = 0; i < m_noOfSubjects; i++)
			{
				m_subjects[i].Subject::display();
			}
			footer();
		}
		else
		{
			cout << "Invalid Transcript!" << endl;
		}
	}
	void Transcript::deallocate()
	{
		delete[] m_studentName;
		delete[] m_subjects;
	}
}

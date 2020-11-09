//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name : Anmol Garg
// Student ID: 149916199
// Student email: agarg15@myseneca.ca
// Date : 6 November, 2020

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <fstream>
#include "Numbers.h"
using namespace std;
namespace sdds {
	Numbers::Numbers() {
		setEmpty();
		m_isOriginal = false;
	}
	Numbers::Numbers(const char* filename) {
		setEmpty();
		m_isOriginal = true;
		setFilename(filename);
		m_numCount = numberCount();
		if (m_numCount == 0 || !load()) {
			delete[] m_numbers;
			delete[] m_filename;
			setEmpty();
			m_isOriginal = false;
		}
		else {
			sort();
		}
	}
	Numbers::Numbers(const Numbers& num)
	{
		setEmpty();
		m_isOriginal = false;
		*this = num;
	}
	Numbers::~Numbers() {
		save();
		delete[] m_numbers;
		delete[] m_filename;
	}

	bool Numbers::isEmpty() const {
		return m_numbers == nullptr;
	}

	void Numbers::setEmpty() {
		m_numbers = nullptr;
		m_filename = nullptr;
		m_numCount = 0;
	}
	void Numbers::setFilename(const char* filename) {
		delete[] m_filename;
		m_filename = new char[strlen(filename) + 1];
		strcpy(m_filename, filename);
	}
	void Numbers::sort() {
		int i, j;
		double temp;
		for (i = m_numCount - 1; i > 0; i--) {
			for (j = 0; j < i; j++) {
				if (m_numbers[j] > m_numbers[j + 1]) {
					temp = m_numbers[j];
					m_numbers[j] = m_numbers[j + 1];
					m_numbers[j + 1] = temp;
				}
			}
		}
	}

	Numbers& Numbers::operator=(const Numbers& num)
	{
		delete[] m_numbers;
		m_numCount = num.m_numCount;
		m_numbers = new double[m_numCount];
		for (int i = 0; i < m_numCount; i++)
		{
			m_numbers[i] = num.m_numbers[i];
		}
		return *this;
	}

	double Numbers::average() const {
		double aver = 0.0;
		if (!isEmpty()) {
			for (int i = 0; i < m_numCount; i++)
				aver += m_numbers[i];
			aver = aver / m_numCount;
		}
		return aver;
	}
	double Numbers::min() const {
		double minVal = 0.0;
		if (!isEmpty()) {
			minVal = m_numbers[0];
			for (int i = 1; i < m_numCount; i++)
				if (minVal > m_numbers[i]) minVal = m_numbers[i];
		}
		return minVal;
	}
	double Numbers::max() const {
		double maxVal = 0.0;
		if (!isEmpty()) {
			maxVal = m_numbers[0];
			for (int i = 1; i < m_numCount; i++)
				if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
		}
		return maxVal;
	}
	int Numbers::numberCount() const
	{
		ifstream fin(m_filename);
		char ch;
		int count = 0;

		while (fin)
		{
			ch = fin.get();
			if (ch == '\n') count++;
		}

		return count;
	}
	bool Numbers::load()
	{
		int i = 0;
		bool succeed = false;

		if (m_numCount > 0)
		{
			m_numbers = new double[m_numCount];
			ifstream fin(m_filename);
			i = 0;
			while (fin)
			{
				fin >> m_numbers[i];
				if (fin) i++;
			}
			if (i == m_numCount)
				succeed = true;
		}
		return succeed;
	}
	void Numbers::save()
	{
		if (m_isOriginal && !isEmpty())
		{
			ofstream fout(m_filename);
			if (fout.is_open())
			{
				for (int i = 0; i < m_numCount; i++)
				{
					fout << m_numbers[i] << endl;
				}
			}
		}
	}
	Numbers& Numbers::operator+=(const double& rightOperand)
	{
		if (!isEmpty())
		{
			int i;
			double* temp = new double[m_numCount + 1];
			for (i = 0; i < m_numCount; i++)
			{
				temp[i] = m_numbers[i];
			}
			m_numCount++;
			temp[i] = rightOperand;
			delete[] m_numbers;
			m_numbers = temp;
			temp = nullptr;
			sort();
		}
		return *this;
	}
	ostream& Numbers::display(ostream& ostr) const
	{
		int i = 0;
		if (isEmpty())
		{
			ostr << "Empty list";
		}
		else
		{
			ostr << "=========================" << endl;
			if (m_isOriginal) 
				ostr << m_filename << endl;
			else 
				ostr << "*** COPY ***" << endl;
			for (i = 0; i < m_numCount - 1; i++)
			{
				ostr << m_numbers[i] << ", ";
			}
			ostr << m_numbers[i] << endl;
			ostr << "-------------------------" << endl;
			ostr << "Total of " << m_numCount << " number(s)" << endl;
			ostr << "Largest number:  " << max() << endl;
			ostr << "Smallest number: " << min() << endl;
			ostr << "Average :        " << average() << endl;
			ostr << "=========================";
		}
		return ostr;
	}
	ostream& operator<<(ostream& os, const Numbers& N)
	{
		return N.display(os);
	}
	istream& operator>>(istream& istr, Numbers& N)
	{
		double value;
		istr >> value;
		N += value;
		return istr;
	}
}

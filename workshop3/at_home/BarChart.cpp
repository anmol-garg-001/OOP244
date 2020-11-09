//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshops and assignments.
// Name : Anmol Garg
// Student ID: 149916199
// Student email: agarg15@myseneca.ca
// Date : 11 Oct, 2020

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "BarChart.h"
using namespace std;

namespace sdds {
	void BarChart::setEmpty()
	{
		m_chart_title = nullptr;
		m_bars = nullptr;
	}
	bool BarChart::isValid() const
	{
		bool valid = false, flag = true;
		int i = 0;

		if (m_chart_title != nullptr && m_bars != nullptr)
		{
			for (i = 0; i < m_noOfSamples && flag; i++)
			{
				flag = m_bars[i].Bar::isValid();
			}
			if (flag)
			{
				valid = true;
			}
		}

		return valid;
	}
	void BarChart::title() const
	{
		cout << m_chart_title << endl;
		line();
	}
	void BarChart::line(char lineChar, int length) const
	{
		int i = 0;
		for (i = 0; i < length; i++)
		{
			cout << lineChar;
		}
		cout << endl;
	}
	void BarChart::init(const char* title, int noOfSampels, char fill)
	{
		int i;
		if (title == NULL || noOfSampels < 1)
		{
			BarChart::setEmpty();
		}
		else
		{
			m_noOfSamples = noOfSampels;
			m_fill = fill;
			m_samplesAdded = 0;
			m_chart_title = new char[strlen(title) + 1];
			strcpy(m_chart_title, title);
			m_bars = new Bar[m_noOfSamples];
			for (i = 0; i < m_noOfSamples; i++)
			{
				m_bars[i].Bar::setEmpty();
			}
		}
	}
	void BarChart::add(const char* bar_title, int value)
	{
		int i;
		bool flag = true;
		if (m_samplesAdded < m_noOfSamples)
		{
			for (i = 0; i < m_noOfSamples && flag; i++)
			{
				if (!m_bars[i].Bar::isValid())
				{
					m_bars[i].set(bar_title, m_fill, value);
					flag = false;
				}
			}
			m_samplesAdded++;
		}
	}
	void BarChart::draw() const
	{
		int i = 0;
		if (BarChart::isValid())
		{
			title();
			for (i = 0; i < m_noOfSamples; i++)
			{
				m_bars[i].Bar::draw();
			}
			line();
		}
		else
		{
			cout << "Invalid Chart!" << endl;
		}
	}
	void BarChart::deallocate()
	{
		delete[] m_chart_title;
		delete[] m_bars;
		m_chart_title = nullptr;
		m_bars = nullptr;
	}
}
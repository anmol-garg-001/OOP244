//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshops and assignments.
// Name : Anmol Garg
// Student ID: 149916199
// Student email: agarg15@myseneca.ca
// Date : 11 Oct, 2020

#ifndef _SDDS_BAR_CHART_H_
#define _SDDS_BAR_CHART_H_
#include "Bar.h"
namespace sdds {
	class BarChart
	{
		char* m_chart_title;
		Bar* m_bars;
		char m_fill;
		int m_noOfSamples;
		int m_samplesAdded;
		void setEmpty();
		bool isValid()const;
		void title()const;
		void line(char lineChar = '-', int length = 71)const;
	public:
		void init(const char* title, int noOfSampels, char fill);
		void add(const char* bar_title, int value);
		void draw()const;
		void deallocate();
	};
}
#endif // !_SDDS_BAR_CHART_H_
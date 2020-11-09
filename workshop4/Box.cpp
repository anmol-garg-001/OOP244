//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshops and assignments.
// Name : Anmol Garg
// Student ID: 149916199
// Student email: agarg15@myseneca.ca
// Date : 13 Oct, 2020

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Box.h"
using namespace std;

namespace sdds {
	void Box::setName(const char* Cstr)
	{
		if (Cstr != nullptr)
		{
			delete[] m_contentName;
			m_contentName = new char[strlen(Cstr) + 1];
			strcpy(m_contentName, Cstr);
		}
	}
	void Box::setUnusable()
	{
		delete[] m_contentName;
		m_contentName = nullptr;
		m_width = m_height = m_length = m_contentVolume = -1;
	}
	bool Box::isUnusable() const
	{
		bool unUsable = false;
		if (m_width == -1 || m_height == -1 || m_length == -1 || m_contentVolume == -1)
		{
			unUsable = true;
		}
		return unUsable;
	}
	bool Box::hasContent() const
	{
		bool content = false;
		if (m_contentVolume > 0 || quantity() > 0)
		{
			content = true;
		}
		return content;
	}
	Box::Box()
	{
		m_height = m_width = m_length = 12;
		m_contentName = nullptr;
		m_contentVolume = 0;
	}
	Box::Box(int sideLength, const char* contentName)
	{
		m_contentName = nullptr;
		if (sideLength < 5 || sideLength > 36)
		{
			setUnusable();
		}
		else
		{
			m_height = m_width = m_length = sideLength;
			m_contentVolume = 0;
			setName(contentName);
		}
	}
	Box::Box(int width, int height, int length, const char* contentName)
	{
		m_contentName = nullptr;
		if (width < 5 || width > 36 || height < 5 || height >36 || length < 5 || length >36)
		{
			setUnusable();
		}
		else
		{
			m_height = height;
			m_width = width;
			m_length = length;
			m_contentVolume = 0;
			setName(contentName);
		}
	}
	Box::~Box()
	{
		delete[] m_contentName;
		m_contentName = nullptr;
	}
	int Box::capacity() const
	{
		return m_height * m_width * m_length;
	}
	int Box::quantity() const
	{
		return m_contentVolume;
	}
	Box& Box::setContent(const char* contentName)
	{
		if (hasContent() && m_contentName != nullptr)
		{
			setUnusable();
		}
		else
		{
			setName(contentName);
		}
		return *this;
	}
	std::ostream& Box::display() const
	{
		if (Box::isUnusable())
		{
			cout << "Unusable box, discard the content, and recycle.";
		}
		else
		{
			char contentName[50] = "Empty box";
			if (m_contentName != nullptr)
			{
				strcpy(contentName, m_contentName);
			}
			cout << setfill('.') << setw(30) << left << contentName << "  ";
			cout.unsetf(ios::left);
			cout << setw(2) << right << setfill('0') << m_width  << "x";
			cout << setw(2) << right << setfill('0') << m_height  << "x";
			cout << setw(2) << right << setfill('0') << m_length  << "  ";
			cout << setw(6) << right << setfill(' ') << quantity() << "/";
			cout << capacity() << " C.I.";
			cout.unsetf(ios::right);
		}
		return cout;
	}
	Box& Box::add(int quantity)
	{
		if (quantity > 0 && quantity + this->quantity() < this->capacity())
		{
			m_contentVolume += quantity;
		}
		else
		{
			setUnusable();
		}
		return *this;
	}
	Box& Box::add(Box& B)
	{
		if (m_contentName == nullptr || quantity() == 0) {
			setContent(B.m_contentName);
		}
		if (strcmp(m_contentName, B.m_contentName) == 0) {
			if (quantity() + B.quantity() <= capacity()) {
				add(B.quantity());
				B.m_contentVolume = 0;
			}
			else {
				B.m_contentVolume -= (capacity() - quantity());
				m_contentVolume = capacity();
			}
		}
		else {
			if (quantity() + B.quantity() <= capacity()) {
				B.m_contentVolume = 0;
			}
			else {
				B.m_contentVolume -= (capacity() - quantity());
			}
			setUnusable();
		}
		return *this;
	}
}


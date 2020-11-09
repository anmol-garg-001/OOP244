//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshops and assignments.
// Name : Anmol Garg
// Student ID: 149916199
// Student email: agarg15@myseneca.ca
// Date : 17 Oct, 2020

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <string>
#include <iostream>
#include <iomanip>
#include "NameTag.h"
using namespace std;

namespace sdds {
	NameTag::NameTag()
	{
		m_name = nullptr;
		m_extension = -1;
	}
	NameTag::NameTag(const char* name)
	{
		m_name = nullptr;
		setName(name);
		m_extension = 0;
	}
	NameTag::NameTag(const char* name, int extension)
	{
		m_name = nullptr;
		setName(name);
		m_extension = extension;
	}
	void NameTag::setName(const char* Cstr)
	{
		if (Cstr != nullptr)
		{
			delete[] m_name;
			m_name = new char[strlen(Cstr) + 1];
			strcpy(m_name, Cstr);
			if (strlen(Cstr) > 40)
			{
				m_name[40] = '\0';
			}
		}
	}
	void NameTag::flushkeys() {
		while (cin.get() != '\n');
	}
	void NameTag::getName()
	{
		char name[50] = { '\0' };
		cin.get(name, 50, '\n');
		flushkeys();
		setName(name);
	}
	bool NameTag::yes()
	{
		bool answer = false;
		char yes;
		cin >> yes;
		flushkeys();
		if (yes == 'y' || yes == 'Y')
		{
			answer = true;
		}
		return answer;
	}
	void NameTag::getExtension()
	{
		int extension;
		cin >> extension;
		flushkeys();
		while (extension < 10000 || extension > 99999)
		{
			cout << "Invalid value [10000<=value<=99999]: ";
			cin >> extension;
			flushkeys();
		}
		m_extension = extension;
	}
	void NameTag::print()
	{
		if (NameTag::isValid())
		{
			string extensionPrinted = "";

			if (m_extension == 0)
			{
				extensionPrinted = "N/A";
			}
			else
			{
				extensionPrinted = to_string(m_extension);
			}

			if (strlen(m_name) < 20)
			{
				cout << "************************" << endl;
				cout << "*                      *" << endl;
				cout << "* " << setw(20) << left << m_name << " *" << endl;
				cout.unsetf(ios::left);
				cout << "*                      *" << endl;
				cout << "* Extension: " << setw(9) << left << extensionPrinted << " *" << endl;
				cout.unsetf(ios::left);
				cout << "*                      *" << endl;
				cout << "************************" << endl;
			}
			else
			{
				cout << "********************************************" << endl;
				cout << "*                                          *" << endl;
				cout << "* " << setw(40) << left << m_name << " *" << endl;
				cout.unsetf(ios::left);
				cout << "*                                          *" << endl;
				cout << "* Extension: " << setw(29) << left << extensionPrinted << " *" << endl;
				cout.unsetf(ios::left);
				cout << "*                                          *" << endl;
				cout << "********************************************" << endl;
			}
		}
		else
		{
			cout << "EMPTY NAMETAG!" << endl;
		}
	}

	NameTag& NameTag::read()
	{

		cout << "Please enter the name: ";
		getName();

		cout << "Would you like to enter an extension? (Y)es/(N)o: ";
		if (yes())
		{
			cout << "Please enter a 5 digit phone extension: ";
			getExtension();
		}
		else
		{
			m_extension = 0;
		}

		return *this;
	}

	bool NameTag::isValid()
	{
		bool valid = false;
		if (m_name != nullptr && (m_extension == 0 || (m_extension >= 10000 && m_extension <= 99999)))
		{
			valid = true;
		}
		return valid;
	}
	NameTag::~NameTag()
	{
		delete[] m_name;
		m_name = nullptr;
	}
}

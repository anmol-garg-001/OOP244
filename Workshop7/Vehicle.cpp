//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name : Anmol Garg
// Student ID: 149916199
// Student email: agarg15@myseneca.ca
// Date : 10 November, 2020

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Vehicle.h"
using namespace std;
namespace sdds {
	Vehicle::Vehicle(const char* plate, const int year)
	{
		strcpy(m_plate, plate);
		strcpy(m_address, "Factory");
		m_year = year;
	}
	void Vehicle::moveTo(const char* address)
	{
		if (strcmp(m_address,address) != 0)
		{
			cout << "|";
			cout.setf(ios::right);
			cout.width(8);
			cout << m_plate << "| |";
			cout.width(20);
			cout << m_address << " ---> ";
			cout.unsetf(ios::right);
			cout.setf(ios::left);
			cout.width(20);
			cout << address << "|" << endl;
			cout.unsetf(ios::left);
			strcpy(m_address, address);
		}
	}
	std::ostream& Vehicle::write(std::ostream& os) const
	{
		os << "| " << m_year << " | " << m_plate << " | " << m_address;
		return os;
	}
	std::istream& Vehicle::read(std::istream& in)
	{
		cout << "Built year: ";
		in >> m_year;
		cout << "License plate: ";
		in.getline(m_plate, 9);
		cout << "Current location: ";
		in.getline(m_address, 64);
		return in;
	}
	std::ostream& operator<<(std::ostream& os, const Vehicle& V)
	{
		return V.write(os);
	}
	std::istream& operator>>(std::istream& istr, Vehicle& V)
	{
		return V.read(istr);
	}
}

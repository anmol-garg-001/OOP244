//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name : Anmol Garg
// Student ID: 149916199
// Student email: agarg15@myseneca.ca
// Date : 10 November, 2020

#include "Truck.h"
using namespace std;
namespace sdds {
	Truck::Truck(const char* plate, const int year, const double capacity, const char* address) :Vehicle(plate, year)
	{
		m_capacity = capacity;
		m_cargo = 0;
		Vehicle::moveTo(address);
	}

	bool Truck::addCargo(double cargo)
	{
		bool change = false;
		double original_cargo = m_cargo;
		m_cargo += cargo;
		if (m_cargo > m_capacity) m_cargo = m_capacity;
		if (original_cargo != m_cargo) change = true;
		return change;
	}

	bool Truck::unloadCargo()
	{
		bool change = false;
		double original_cargo = m_cargo;
		m_cargo = 0;
		if (original_cargo != m_cargo) change = true;
		return change;
	}

	std::ostream& Truck::write(std::ostream& os) const
	{
		Vehicle::write(os);
		os << " | " << m_cargo << "/" << m_capacity;
		return os;
	}

	std::istream& Truck::read(std::istream& in)
	{
		Vehicle::read(in);
		cout << "Capacity: ";
		in >> m_capacity;
		cout << "Cargo: ";
		in >> m_cargo;
		return in;
	}

	std::ostream& operator<<(std::ostream& os, const Truck& T)
	{
		return T.write(os);
	}

	std::istream& operator>>(std::istream& istr, Truck& T)
	{
		return T.read(istr);
	}
}
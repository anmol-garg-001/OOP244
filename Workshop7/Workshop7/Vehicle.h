//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name : Anmol Garg
// Student ID: 149916199
// Student email: agarg15@myseneca.ca
// Date : 10 November, 2020

#ifndef _SDDS_VEHICLE_H_
#define _SDDS_VEHICLE_H_
#include <iostream>
namespace sdds {
	class Vehicle
	{
		char m_plate[9];
		char m_address[64];
		int m_year;
	public:
		Vehicle(const char* plate,const int year);
		void moveTo(const char* address);
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& os, const Vehicle& V);
	std::istream& operator>>(std::istream& istr, Vehicle& V);
}
#endif // !_SDDS_VEHICLE_H_
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name : Anmol Garg
// Student ID: 149916199
// Student email: agarg15@myseneca.ca
// Date : 10 November, 2020

#ifndef _SDDS_TRUCK_H_
#define _SDDS_TRUCK_H_
#include "Vehicle.h"
namespace sdds {
	class Truck:public Vehicle
	{
		double m_capacity;
		double m_cargo;
	public:
		Truck(const char* plate,const int year,const double capacity, const char* address);
		bool addCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& os, const Truck& T);
	std::istream& operator>>(std::istream& istr, Truck& T);
}
#endif // !_SDDS_TRUCK_H_
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshops and assignments.
// Name : Anmol Garg
// Student ID: 149916199
// Student email: agarg15@myseneca.ca
// Date : 20 Oct, 2020

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
	void Account::setEmpty() {
		m_number = -1;
		m_balance = 0.0;
	}
	// New account
	Account::Account() {
		m_number = 0;
		m_balance = 0.0;
	}
	Account::Account(int number, double balance) {
		setEmpty();
		if (number >= 10000 && number <= 99999
			&& balance > 0) {
			m_number = number;
			m_balance = balance;
		}
	}
	std::ostream& Account::display() const {
		if (*this) {
			cout << "Acc#: ";
			if (~(*this))
				cout << "Not Set";
			else
				cout << " " << m_number << " ";
			cout << ", Balance: ";
			cout.width(12);
			cout.precision(2);
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout << m_balance;
			cout.unsetf(ios::right);
			return cout;
		}
		else {
			cout << "Invalid Account";
		}
		return cout;
	}
	Account::operator int() const
	{
		return m_number;
	}
	Account::operator double() const
	{
		return m_balance;
	}
	bool Account::operator~()const
	{
		return !m_number;
	}
	Account::operator bool() const
	{
		bool valid = false;
		if (m_number == 0 || (m_number >= 10000 && m_number <= 99999))
		{
			valid = true;
		}
		return valid;
	}
	Account& Account::operator+=(const double& RightOperand)
	{
		if (*this && RightOperand > 0)
		{
			m_balance += RightOperand;
		}
		return *this;
	}
	Account& Account::operator-=(const double& RightOperand)
	{
		if (*this && RightOperand >= 0 && m_balance >= RightOperand)
		{
			m_balance -= RightOperand;
		}
		return *this;
	}
	Account& Account::operator=(const int& RightOperand)
	{
		if (RightOperand < 10000 || RightOperand > 99999)
		{
			setEmpty();
		}
		else if (*this)
		{
			m_number = RightOperand;
		}
		return *this;
	}
	Account& Account::operator=(Account& RightOperand)
	{
		if (*this && RightOperand)
		{
			m_balance = RightOperand.m_balance;
			RightOperand.m_balance = 0;
		}
		return *this;
	}
	double operator+(const Account& LeftOperand, const Account& RightOperand)
	{
		double sum = 0.0;
		if (LeftOperand && RightOperand)
		{
			sum = double(LeftOperand) + double(RightOperand);
		}
		return sum;
	}
	double operator+=(double& LeftOperand, const Account& RightOperand)
	{
		double sum = 0.0;
		if (LeftOperand >= 0 && RightOperand)
		{
			sum = LeftOperand += double(RightOperand);
		}
		return sum;
	}
}
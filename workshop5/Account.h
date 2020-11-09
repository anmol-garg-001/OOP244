//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshops and assignments.
// Name : Anmol Garg
// Student ID: 149916199
// Student email: agarg15@myseneca.ca
// Date : 20 Oct, 2020

#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;
      operator int() const;
      operator double() const;
      operator bool() const;
      bool operator~()const;
      Account& operator+=(const double& RightOperand);
      Account& operator-=(const double& RightOperand);
      Account& operator=(const int& RightOperand);
      Account& operator=(Account& RightOperand);
   };
   double operator+(const Account& LeftOperand,const Account& RightOperand);
   double operator+=(double& LeftOperand,const Account& RightOperand);
}
#endif // SDDS_ACCOUNT_H_
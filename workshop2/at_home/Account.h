//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshops and assignments.
// Name : Anmol Garg
// Student ID: 149916199
// Student email: agarg15@myseneca.ca
// Date : 3 October, 2020

#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
namespace sdds {
	struct Account {
		int m_accountNumber;
		double m_balance;
	};
	void sort();
	bool load(Account* account);
	bool load(const char filename[]);
	void display(const Account* account);
	void display();
	void deallocateMemory();
}
#endif // SDDS_ACCOUNT_H_
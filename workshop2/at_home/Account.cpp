//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshops and assignments.
// Name : Anmol Garg
// Student ID: 149916199
// Student email: agarg15@myseneca.ca
// Date : 3 October, 2020

#include <iostream>
#include "Account.h"
#include "File.h"

using namespace std;
namespace sdds {
	int noOfAccounts;
	Account* accounts;

	void sort() {
		int i, j;
		Account temp;
		for (i = noOfAccounts - 1; i > 0; i--) {
			for (j = 0; j < i; j++) {
				if (accounts[j].m_balance > accounts[j + 1].m_balance) {
					temp = accounts[j];
					accounts[j] = accounts[j + 1];
					accounts[j + 1] = temp;
				}
			}
		}
	}

	bool load(Account* account) {
		bool ok = false;
		ok = read(&account->m_accountNumber) && read(&account->m_balance);
		return ok;
	}

	bool load(const char filename[]) {
		bool ok = false;
		int i = 0;
		if (openFile(filename)) {
			noOfAccounts = noOfRecords();

			accounts = new Account[noOfAccounts];

			for (i = 0; i < noOfAccounts; i++)
			{
				load(&accounts[i]);
			}

			if (i != noOfAccounts) {
				cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
			}
			else {
				ok = true;
			}
			closeFile();
		}
		else {
			cout << "Could not open data file: " << filename << endl;
		}
		return ok;
	}
	void display(const Account* account)
	{
		cout << account->m_accountNumber << ":  " << account->m_balance << endl;
	}

	void display()
	{
		int i = 0;
		sort();

		cout << "Account#: Balance" << endl;
		for (i = 0; i < noOfAccounts; i++)
		{
			cout << i + 1 <<": ";
			display(&accounts[i]);
		}
	}

	// TODO: Implementation for the deallocateMemory function goes here
	void deallocateMemory()
	{
		delete[] accounts;
	}
}

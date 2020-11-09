//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshops and assignments.
// Name : Anmol Garg
// Student ID: 149916199
// Student email: agarg15@myseneca.ca
// Date : 17 Oct, 2020

#ifndef _SDDS_NAME_TAG_H_
#define _SDDS_NAME_TAG_H_
namespace sdds {
	class NameTag
	{
		char* m_name;
		int m_extension;
		void setName(const char* Cstr);
		void flushkeys();
		void getName();
		bool yes();
		void getExtension();
	public:
		NameTag();
		NameTag(const char* name);
		NameTag(const char* name, int extension);
		~NameTag();
		void print();
		NameTag& read();
		bool isValid();
	};
}
#endif // !_SDDS_NAME_TAG_H_
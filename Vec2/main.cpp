#include <cctype>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <vector>


#include "MyFunctions.h"
#include "Sales_data.h"

namespace standart
{
	using std::vector;
	using std::string;
	using std::cout;
	using std::cin;
	using std::endl;
}


class Person
{
public:
	Person() : name("Name"), adress("Adress") {};
	Person(std::string nameIn, std::string adressIn) : name(nameIn), adress(adressIn) {};

	std::string getName() const { return name; }
	std::string getAdress() const { return adress; }

	void setName(std::string nameIn) { name = nameIn; }
	void setAdress(std::string adressIn) { adress = adressIn; }


private:
	std::string name;
	std::string adress;

};

class Debug
{
public:

	constexpr Debug(bool b = true) : hardware(b), io(b), other(b) {};
	constexpr Debug(bool h, bool i, bool o) : hardware(h), io(i), other(o) {};
	constexpr bool any()
	{
		return hardware || io || other;
	}

	void set_io(bool b) { io = b; }
	void set_hardware(bool b) { hardware = b; }
	void set_other(bool b) { other = b; }

private:
	bool hardware; //Hardware error
	bool io; // IO error
	bool other; // Other errors
};


std::ostream& printInfo(std::ostream& os, const Person& person)
{
	os << "Name: " << person.getName() << " Adress: " << person.getAdress();
	return os;
}

struct PersonInfo
{
	std::string name;
	std::vector<std::string> phones;
};



int main(int argc, char* argv[])
{
	std::string line, word;
	std::vector<PersonInfo> people;
	std::istringstream record;
	std::ifstream readFile("ReadFile.txt");

	while (std::getline(readFile, line))
	{
		PersonInfo info;
		record.clear();
		record.str(line);
		record >> info.name;
		while (record >> word)
		{
			info.phones.push_back(word);
			
		}
		people.push_back(info);
		
	}
	for (auto p : people)
	{
		std::cout << p.name << " ";
		for (auto s : p.phones)
			std::cout << s << " ";
		std::cout << std::endl;
	}


	system("PAUSE");
	return 0;
}


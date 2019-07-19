#include <cctype>
#include <ctime>
#include <fstream>
#include <iostream>
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



int main(int argc, char* argv[])
{

	Sales_data obj;

	std::ifstream input(argv[1]);
	std::ofstream output(argv[2], std::ios::app);

	read(input, obj);
	input.close();
	print(output, obj);
	output.close();

	system("PAUSE");
	return 0;
}


#include <algorithm>
#include <cctype>
#include <ctime>
#include <deque>
#include <forward_list>
#include <fstream>
#include <iostream>
#include <list>
#include<numeric>
#include <sstream>
#include <stack>
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
using namespace std::placeholders;


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
	
	std::vector<std::string> v{ "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle" };

	std::vector<int> vec{ 1,2,3,4,2,23,11,22,2,3 };
	std::string str{ "asdasd" };
	auto result = std::find_if(vec.begin(), vec.end(), std::bind(check_size, str, _1));

	if (result != vec.end())
		std::cout << *result << std::endl;
	else
		std::cout << "Not found" << std::endl;
	
	system("PAUSE");
	return 0;
}


#include <cctype>
#include <ctime>
#include <deque>
#include <forward_list>
#include <fstream>
#include <iostream>
#include <list>
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


int main(int argc, char* argv[])
{
	std::vector<int> myVec;
	std::list<int> myList;
	std::forward_list<int> fwList = { 0,1,1,2,3,5,8,13,21,55,89 };
	auto prev = fwList.before_begin();
	auto current = fwList.begin();
	while (current != fwList.end())
	{
		if (*current%2 == 1)
		{
			current = fwList.erase_after(prev);
		}
		else
		{
			current++;
			prev++;
		}
	}

	for (auto i : fwList)
	{
		std::cout << i;
	}

	int ia[] = { 0,1,1,2,3,5,8,13,21,55,89 };
	int size = sizeof(ia) / sizeof(ia[0]);
	for (size_t i = 0; i < size; i++)
	{
		myVec.push_back(ia[i]);
		myList.push_back(ia[i]);
	}
	for (auto iter = myVec.begin(); iter != myVec.end();)
	{
		if (*iter%2 == 0)
		{
			iter = myVec.erase(iter);
		}
		else
		{
			iter++;
		}
	}

	std::cout << "Vector:\n";
	for (auto i : myVec)
	{
		std::cout << i << " ";
	}

	for (auto iter = myList.begin(); iter != myList.end();)
	{
		if (*iter % 2 == 1)
		{
			iter = myList.erase(iter);
		}
		else
		{
			iter++;
		}
	}

	std::cout << "\nList:\n";
	for (auto i : myList)
	{
		std::cout << i << " ";
	}

	

	system("PAUSE");
	return 0;
}


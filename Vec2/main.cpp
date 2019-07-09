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


class Screen
{
public:
	friend class Window_mgr;
	typedef std::string::size_type pos;
	Screen() = default;
	Screen(pos height, pos width, char c) : height(height), width(width), contents(width * height, c) {};

	char get() const { return contents[cursor]; }
	char get(pos r, pos c) const
	{
		pos row = r * width;
		return contents[row + c];
	}

	inline Screen& set(char c)
	{
		contents[cursor] = c;
		return *this;
	}
	inline Screen& set(pos row, pos col, char ch)
	{
		contents[row * width + col] = ch;
		return *this;
	}

	Screen& display(std::ostream& os)
	{
		do_display(os);
		return *this;
	}
	const Screen& display(std::ostream& os) const
	{
		do_display(os);
		return *this;
	}

	void draw()
	{
		int counter = 0;
		std::cout << std::endl;
		for (size_t i = 0; i < height; i++)
		{
			for (size_t j = 0; j < width; j++)
			{
				std::cout << contents[counter];
				counter++;
			}
			std::cout << std::endl;
		}
	}

	Screen& move(pos r, pos c)
	{
		pos row = r * width;
		cursor = row + c;
		return *this;
	}
private:
	void do_display(std::ostream& os) const
	{
		os << contents;
	}
	pos width = 0, height = 0;
	pos cursor = 0;
	std::string contents;
};

class Window_mgr
{
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	void clear(ScreenIndex i)
	{
		Screen& s = screens[i];
		s.contents = std::string(s.height * s.width, '0');
	}

private:
	std::vector<Screen> screens{ Screen(24,80,'1') };
};

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


std::ostream& printInfo(std::ostream& os, const Person& person)
{
	os << "Name: " << person.getName() << " Adress: " << person.getAdress();
	return os;
}

int main()
{
	Screen screen1(3,3,'a');
	screen1.move(0,8).set('#').display(std::cout);
	std::cout << "\n";

	

	system("PAUSE");
	return 0;
}


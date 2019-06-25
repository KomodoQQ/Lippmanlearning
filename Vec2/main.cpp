#include <cctype>
#include <ctime>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <vector>


#include "MyFunctions.h"

namespace standart
{
	using std::vector;
	using std::string;
	using std::cout;
	using std::cin;
	using std::endl;
}

int (*func1)(int a, int b);
int sumInts(int a, int b)
{
	return a + b;
}


int main(int argc, char* argv[])
{	
	std::vector<decltype(func1)> v1;
	func1 = sumInts;
	v1.push_back(func1);

	for (auto i = v1.begin(); i != v1.end(); i++)
	{
		std::cout << i;
	}

	system("PAUSE");
	return 0;
}


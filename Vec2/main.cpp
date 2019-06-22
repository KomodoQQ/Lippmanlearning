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



int main(int argc, char* argv[])
{	
	for (size_t i = 0; i < argc; i++)
	{
		std::cout << argv[i] << "\n";
	}
	
	system("PAUSE");
	return 0;

}

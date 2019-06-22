#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <initializer_list>

namespace standart
{
	using std::vector;
	using std::string;
	using std::cout;
	using std::cin;
	using std::endl;
}


//Iterators 3.4. Reading line of integers from 0 to 100 and dividing that numbers on clusters (0-9, 10-19 ... etc)
int clasterisation()
{
	std::vector<unsigned> scores(11, 0);
	unsigned grade;
	auto beg = scores.begin(), end = scores.end();
	while (std::cin >> grade && grade != -1)
	{
		if (grade <= 100)
		{
			beg = beg + (grade / 10);
			(*beg) += 1;
			beg = scores.begin();
		}
	}

	for (auto i = scores.begin(); i < scores.end(); i++)
	{
		std::cout << (*i) << " ";
	}

	return 0;
}

void printBinary(int number)
{
	bool currentByte;
	int counter = 0;
	for (int i = 31; i >= 0; --i)
	{
		std::cout << (currentByte = number & (1UL << i));
		++counter;
		if (counter == 4)
		{
			std::cout << " ";
			counter = 0;
		}
	}
}

void printBinary(char character)
{
	bool currentByte;
	int counter = 0;
	for (int i = 7; i >= 0; --i)
	{
		std::cout << (currentByte = character & (1UL << i));
		++counter;
		if (counter == 4)
		{
			std::cout << " ";
			counter = 0;
		}
	}
}

void findRepeatedWords()
{
	std::string s1;
	std::string temp = "", finalWord;
	int counter = 1, maximum = 0;

	while (std::cin >> s1)
	{
		if (s1 == "-1")
		{
			break;
		}

		if (s1 == temp)
		{
			++counter;
			if (maximum < counter)
			{
				maximum = counter;
				finalWord = s1;

			}

		}
		else if (s1 != temp)
		{
			counter = 1;
		}

		temp = s1;


	}
	if (maximum != 0)
	{
		std::cout << " Word \"" << finalWord << "\" was found " << maximum << " times in a row! \n";
	}
	else
	{
		std::cout << "No repeated words in text!";
	}

}

//Checking the occurrence of one vector in another in the prefix . Task 5.17 p251

bool vecPrefixCompare(std::vector<int> &v1, std::vector<int> &v2)
{
	if (v1.size() < v2.size())
	{
		for (size_t i = 0; i < v1.size(); i++)
		{
			if (v1[i] != v2[i])
			{
				std::cout << "Error! Two different vectors";
				return false;
			}

		}
		std::cout << "V1 is prefix of v2";
		return true;
	}
	else
	{
		for (size_t i = 0; i < v2.size(); i++)
		{
			if (v1[i] != v2[i])
			{
				std::cout << "Error! Two different vectors";
				return false;
			}

		}
		std::cout << "V2 is prefix of v1";
		return true;

	}
}

int factorial(int numIn)
{
	if (numIn < 0)
	{
		std::cout << "Wrong number";
		return -1;
	}
	int result = 1;
	for (int i = 1; i <= numIn; i++)
	{
		result *= i;
	}
	return result;
}

int absolute(int numIn)
{
	if (numIn < 0)
	{
		numIn *= -1;
	}
	return numIn;
}

std::string stringToLower(std::string& s1)
{
	for (auto iter = 0; iter != s1.size(); ++iter)
	{
		if (!islower(s1[iter]))
		{
			s1[iter] = tolower(s1[iter]);
		}
	}

	return s1;
}

// Changing 1 number in Vector for another. Task 6.18 (p283)
std::vector<int>::iterator change_val(int number, std::vector<int>::iterator iter)
{
	*iter = number;
	return iter;
}

void printVector(const std::vector<int> vecIn)
{
	for (auto it : vecIn)
	{
		std::cout << it << " ";
	}
}

void showCmdArgs(int argc, char* argv[])
{
	if (argc > 1)
	{
		for (size_t i = 1; i < argc; i++)
		{
			std::cout << argv[i] << "\n";
		}
	}
}

int sumListNumbers(std::initializer_list<int> numIn)
{
	int result = 0;
	for (auto beg = numIn.begin(); beg != numIn.end(); beg++)
	{
		result += *beg;
	}
	return result;
}

const std::string& shorterString(const std::string& s1, const std::string& s2)
{
	return s1.size() <= s2.size() ? s1 : s2;
}

void print(int intNum)
{
	std::cout << intNum << std::endl;
}




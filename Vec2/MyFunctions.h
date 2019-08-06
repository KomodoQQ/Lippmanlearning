#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <functional>
#include <vector>
#include <initializer_list>
#include <cassert>


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

inline const std::string& shorterString(const std::string& s1, const std::string& s2)
{
	return s1.size() <= s2.size() ? s1 : s2;
}

void print(int intNum)
{
	std::cout << intNum << std::endl;
}

void print( const std::vector<int> vecIn)
{
	for (auto iter : vecIn)
	{
		std::cout << iter << " ";
	}
	std::cout << std::endl;
}

void horseTimeConverter(int numIn)
{
	
	int time = numIn / 3000;
	int hours = time / 60;
	int minutes = time % 60;
	
	std::cout << hours << "h " << minutes << "m" << std::endl;

}

void horseTimeCalc()
{
	int num = 0, sum = 0;
	std::vector<int> experience;
	while (std::cin >> num && num != 0)
	{
		experience.push_back(num);
		sum += num;
	}
	int counter = 1;
	for (auto i : experience)
	{
		std::cout << counter << " lvl " << i << "exp" << " = ";
		horseTimeConverter(i);
		counter++;
	}
	counter = 1;
	int time = sum / 3000;
	int hours = time / 60;
	int minutes = time % 60;
	std::cout << "\n" << hours << "h " << minutes << "m" << std::endl;
	
}

std::istream& streamFunc(std::istream& obj) //8.1.2 (p.404)
{
	auto state = obj.rdstate();
	std::string a;
	while (obj >> a)
	{
		std::cout << a << " ";
	}

	obj.clear();	
	return obj;
}

void filetoVec(std::string fileName, std::vector<std::string>& vecIn) //Reading from file into vector of strings
{
	std::ifstream readStream;
	readStream.open(fileName);
	
	std::string str;
	
	while (!readStream.eof())
	{
		std::getline(readStream, str);
		vecIn.push_back(str);
	}
	
	readStream.close();
}

std::vector<int>::iterator checkNumberinVector(std::vector<int>::iterator begin, std::vector<int>::iterator end, int numIn) //Task 9.4
{
	auto result = begin;
	while (begin != end)
	{
		if (*begin == numIn)
		{
			result = begin;
			return result;
		}
		begin++;
	}
	std::cout << "Number %d was not found!", numIn;
	return result;
}

void addToForwardList(std::forward_list<std::string>& list, std::string const& checkStr, std::string const& insertString)
{
	auto prev = list.before_begin();
	for (auto i = list.begin(); i != list.end(); i++)
	{
		if (*i == checkStr)
		{
			list.insert_after(i, insertString);
			return;
		}
		prev++;
	}
	list.insert_after(prev, insertString);
}

//Task 9.44 p 467
void replace_word(std::string& s, std::string oldVal,const std::string& newVal)
{

	for (size_t i = 0; i <= s.size() - oldVal.size();)
	{
		std::string temp(s, i, oldVal.size());
		if (temp == oldVal)
		{
			s.replace(i, oldVal.size(), newVal);
			i += oldVal.size();
		}
		else
		{
			i++;
		}

	}

}
//Task 9.45 p 467
void nameChange(std::string& name, std::string prefix, const std::string& suffix)
{
	name.insert(name.begin(),prefix.begin(),prefix.end());
	name.append(suffix);
}

void numSearch(std::string str)
{
	std::string numbers = { "0123456789" };
	std::string::size_type pos = 0;
	while ((pos = str.find_first_of(numbers, pos)) != std::string::npos)
	{
		std::cout << str[pos];
		pos++;
	}
	std::cout << std::endl;
	pos = 0;
	while ((pos = str.find_first_not_of(numbers, pos)) != std::string::npos)
	{
		std::cout << str[pos];
		pos++;
	}
	std::cout << std::endl;
}

void elimDups(std::vector<std::string>& vec)
{
	std::sort(vec.begin(), vec.end());
	
	auto forErase = std::unique(vec.begin(), vec.end());
	
	vec.erase(forErase, vec.end());	
}

bool isShorter(const std::string& s1, const std::string& s2)
{
	return s1.size() < s2.size();
}

bool lengthShorter(const std::string& s1)
{
	if (s1.size() == 5)
	{
		return true;
	}
	else return false;
}

void stringToWords(const std::string& strIn, std::vector<std::string>& vecIn)
{
	std::istringstream stream(strIn);
	std::string word;
	
	while (stream >> word)
	{
		vecIn.push_back(word);
	}
		
}

void biggies(std::vector<std::string>& words, std::vector<std::string>::size_type sz)
{
	elimDups(words);
	std::stable_sort(words.begin(), words.end(), [](const std::string& a, const std::string& b)
		{return a.size() < b.size(); });
	auto wc = find_if(words.begin(), words.end(), [sz](const std::string& a) {return a.size() >= sz; });

	auto count = words.end() - wc;
	std::cout << count << " words of size " << sz << " or higher" << std::endl;

	std::for_each(wc, words.end(), [](const std::string& s) {std::cout << s << " "; });
	std::cout << std::endl;
}

bool check_size(const std::string& str, size_t sz)
{
	return str.size() < sz;
}


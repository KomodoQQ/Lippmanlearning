#include <algorithm>
#include <cctype>
#include <ctime>
#include <deque>
#include <forward_list>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <set>
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
//using namespace std;


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

class QueryResult
{
	friend std::ostream& print(std::ostream& os, const QueryResult& qr)
	{
		os << qr.sought << " occurs " << qr.lines->size() << " "
			<< "times" << std::endl;
		for (auto num : *qr.lines)
		{
			os << "\t(line" << num + 1 << ") " << *(qr.file->begin() + num) << std::endl;
		}
		return os;
	}
public:
	using line_no = std::vector<std::string>::size_type;
	QueryResult(std::string s,
		std::shared_ptr<std::set<line_no>> p,
		std::shared_ptr<std::vector<std::string>> f) :
		sought(s), lines(p), file(f) {}

private:
	std::string sought;
	std::shared_ptr<std::set<line_no>> lines;
	std::shared_ptr<std::vector<std::string>> file;

};

class TextQuery
{
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream& is) : file(new std::vector<std::string>)
	{
		std::string text;
		while (std::getline(is, text))
		{
			file->push_back(text);
			size_t n = file->size() - 1;
			std::istringstream line(text);
			std::string word;
			while (line >> word)
			{
				auto& lines = wm[word];
				if (!lines)
				{
					lines.reset(new std::set<line_no>);
				}
				lines->insert(n);
			}
		}

	}
	QueryResult query(const std::string& sought) const
	{
		static std::shared_ptr<std::set<line_no>> nodata(new std::set <line_no>);
		auto loc = wm.find(sought);
		if (loc == wm.end())
		{
			return QueryResult(sought, nodata, file);
		} else 
		{ 
			return QueryResult(sought, loc->second, file);
		}
	}
private:
	std::shared_ptr<std::vector<std::string>> file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

class HasPtr // Task 13.5
{
public:
	void swap(HasPtr& rhs)
	{
		using std::swap;
		swap(ps, rhs.ps);
		swap(i, rhs.i);
		std::cout << "Objects swaped!";
	}
	

	friend bool operator<(const HasPtr& lhs, const HasPtr& rhs)
	{
		return *lhs.ps < *rhs.ps;
	}

	HasPtr(const HasPtr& obj) : ps(new std::string(*obj.ps)), i(obj.i) {}
	HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}

	HasPtr& operator=(HasPtr obj) //Task 13.8
	{
		this->swap(obj);
		return *this;
	}
	~HasPtr() { delete ps; }
	
private:
	std::string* ps;
	int i;
};

class X {
public:
	X() { std::cout << "X()" << std::endl; }
	X(const X&) { std::cout << "X(const X&)" << std::endl; }
	X& operator=(const X&) { std::cout << "X& operator=(const X&)" << std::endl; return *this; }
	~X() { std::cout << "~X()" << std::endl; }
};

class TreeNode
{
public:
	TreeNode(const TreeNode& obj) : count(obj.count), left(obj.left), right(obj.right), value(obj.value) { ++*count; }
	TreeNode() : value(std::string()), count(new int(1)), left(nullptr), right(nullptr) { }
	TreeNode& operator=(TreeNode& obj)
	{
		obj.count++;
		if (--*obj.count == 0)
		{
			delete left;
			delete right;
			delete count;
		}
		value = obj.value;
		count = obj.count;
		right = obj.right;
		left = obj.left;
		return *this;
	}
	~TreeNode()
	{
		if (--*count == 0)
		{
			delete left;
			delete right;
			delete count;
		}
	}
private:
	std::string value;
	int* count;
	TreeNode* left;
	TreeNode* right;
};

class BinStrTree {
public:
	BinStrTree() : root(new TreeNode()) { }
	BinStrTree(const BinStrTree& obj) : root(new TreeNode(*obj.root)) { }
	BinStrTree& operator=(BinStrTree& obj)
	{
		TreeNode* buffer = new TreeNode(*obj.root);
		delete root;
		root = buffer;
		return *this;
	}
	~BinStrTree() { delete root; }

private:
	TreeNode* root;
};


std::ostream& printInfo(std::ostream& os, const Person& person)
{
	os << "Name: " << person.getName() << " Adress: " << person.getAdress();
	return os;
}


int main(int argc, char* argv[])
{

	std::vector<HasPtr> vec(3);
	
	std::sort(vec.begin(), vec.end());

	system("PAUSE");
	return 0;
}


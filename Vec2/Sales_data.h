#pragma once
#include <string>
#include <iostream>
class Sales_data
{
	friend std::istream& read(std::istream& is, Sales_data& item);
	friend std::ostream& print(std::ostream& os, const Sales_data& item);
	friend Sales_data add(const Sales_data& lhs, const Sales_data& rhs);
	friend bool compareIsbn(Sales_data& obj1, Sales_data& obj2);

public:
	Sales_data() = default;
	Sales_data(const std::string& s) : isbn(s) {};
	Sales_data(const std::string& s, unsigned n, double p) : isbn(s), units_sold(n), revenue(p* n) {};
	Sales_data(std::istream&);

	std::string getIsbn() const { return isbn; }
	Sales_data& combine(const Sales_data&);

private:

	inline double avg_price() const
	{
		return units_sold ? revenue / units_sold : 0;
	}
	std::string isbn;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream& print(std::ostream&, const Sales_data&);
std::istream& read(std::istream&, Sales_data&);
bool compareIsbn(Sales_data&, Sales_data&);
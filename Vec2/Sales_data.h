#pragma once
#include <string>
#include <iostream>
class Sales_data
{
	friend std::istream& read(std::istream& is, Sales_data& item);
	friend std::ostream& print(std::ostream& os, const Sales_data& item);
	friend Sales_data add(const Sales_data& lhs, const Sales_data& rhs);
public:
	Sales_data(const std::string& s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p* n) { std::cout << "Base"; };
	Sales_data() : Sales_data(" ", 0, 0) { std::cout << "First"; };
	Sales_data(const std::string& s) : Sales_data(s,0,0) { std::cout << "Second"; };
	Sales_data(std::istream& is) : Sales_data() { std::cout << "Third"; read(is, *this);  };

	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);

private:

	inline double avg_price() const
	{
		return units_sold ? revenue / units_sold : 0;
	}
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream& print(std::ostream&, const Sales_data&);
std::istream& read(std::istream&, Sales_data&);
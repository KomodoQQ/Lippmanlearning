#include "Sales_data.h"

Sales_data::Sales_data(std::istream& is) : Sales_data::Sales_data()
{
	read(is, *this);
}



Sales_data& Sales_data::combine(const Sales_data& rhs)
{
	//isbn += rhs.isbn;
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

bool compareIsbn(Sales_data& obj1, Sales_data& obj2)
{
	return obj1.getIsbn().size() < obj2.getIsbn().size();
}

std::istream& read(std::istream& is, Sales_data& item)
{
	double price = 0;
	is >> item.isbn >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

std::ostream& print(std::ostream &os, const Sales_data& item)
{
	os << item.getIsbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}
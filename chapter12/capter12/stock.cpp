#include <iostream>
#include "stock.h"

Stock::Stock()
{
	company = new char[8];
	strcpy_s(company, 8, "no name");
	shares = 0;
	share_val = 0;
	set_tot();
}

Stock::Stock(const char* co, long n, double pr)
{
	company = new char[strlen(co) + 1];
	strcpy_s(company, strlen(co) + 1, co);
	if (n < 0)
	{
		std::cout << "Number of shares can't be negative; "
			<< company << " shares set to 0.\n";
		shares = 0;
	}
	else
	{
		shares = n;
	}
	share_val = pr;

	set_tot();
}




Stock::~Stock() {
	// std::cout << "Bye " << company << std::endl;
	delete[] company;
}

void Stock::buy(long num, double price)
{
	if (num < 0)
	{
		std::cout << "Number of shares can't be negative; "
			<< "Transaction is aborted.\n";
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}

void Stock::sell(long num, double price)
{
	using std::cout;
	if (num < 0)
	{
		cout << "Number of shares can't be negative; "
			<< "Transaction is aborted.\n";
	}
	else if (num > shares)
	{
		cout << "You can't sell more than you have! "
			<< "Transaction is aborted.\n";
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	share_val = price;
	set_tot();
}


const Stock& Stock::topval(const Stock& s) const
{
	if (s.total_val > total_val)
	{
		return s;
	}
	else
	{
		return *this;
	}
}

Stock& Stock::operator=(const Stock& st)
{
	if (this == &st)
	{
		return *this;
	}
	delete[] company;

	company = new char[strlen(st.company) + 1];
	strcpy_s(company, strlen(st.company) + 1, st.company);
	shares = st.shares;
	share_val = st.share_val;
	set_tot();
	return *this;
}

std::ostream& operator<<(std::ostream& os , const Stock& st)
{
	os << "Company: " << st.company
		<< "  Shares: " << st.shares << "\n"
		<< "  Share Prices: $" << st.share_val
		<< "  Total Worth: $" << st.total_val << "\n";
	return os;
}

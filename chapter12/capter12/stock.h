#include <ostream>

#ifndef __STOCK__H__
#define __STOCK__H__


class Stock
{
public:
	Stock();
	Stock(const char* co, long n, double pr);
	~Stock();
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	const Stock& topval(const Stock& s) const;
	friend std::ostream& operator<< (std::ostream&, const Stock&);
	Stock& operator=(const Stock& st);
private:
	char* company;
	long shares;
	double share_val;
	double total_val;
	void set_tot() { total_val = shares * share_val; }
};

#endif // !__STOCK10__H__
#pragma once

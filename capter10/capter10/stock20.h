
#ifndef __STOCK20__H__
#define __STOCK20__H__

#include <string>

class Stock
{
public:
	Stock();
	Stock(const std::string& co, long n, double pr);
	~Stock();
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	void show() const;
	const Stock& topval(const Stock& s) const;

private:
	std::string company;
	long shares;
	double share_val;
	double total_val;
	void set_tot() { total_val = shares * share_val; }
};

#endif // !__STOCK10__H__
#pragma once

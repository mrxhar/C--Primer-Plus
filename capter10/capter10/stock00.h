#ifndef __STOCK00__H__
#define __STOCK00__H__

#include <string>

class Stock
{
public:
	void acquire(const std::string& co, long n, double pr);
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	void show();

private:
	std::string company;
	long shares;
	double share_val;
	double total_val;
	void set_tot() { total_val = shares * share_val; }
	Stock(const std::string& co, long n, double pr);
};

#endif // !__STOCK00__H__

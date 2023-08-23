#include "golf.h"

golf::golf(const char* name, int hc)
{
	strcpy_s(fullname, name);
	handicap = hc;
}

golf::golf()
{
	std::cout << "The fullname is:";
	std::cin.getline(fullname, Len);
	std::cout << "The handicap is:";
	std::cin >> handicap;
	std::cin.get();
}

void golf::sethandicap(int hc)
{
	handicap = hc;
}

void golf::showgolf() const
{
	std::cout << "The fullname is:" << fullname << "\n";
	std::cout << "The handicap is:" << handicap << "\n";
}
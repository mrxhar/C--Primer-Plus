#include "list.h"
#include <iostream>

int main(void)
{
	List list;
	Item num;
	for (int i = 0; i < 2; i++)
	{
		std::cout << "Please enter a number: ";
		std::cin >> num;
		list.add(num);
		list.visit(visit_item);
	}

	return 0;
}
#include "list.h"
#include <iostream>

List::List()
{
	top = 0;
}

bool List::isempty() const
{
	return top == 0;
}

bool List::is_full() const
{
	return top == MAX;
}

bool List::add(const Item& item)
{
	if (top < MAX)
	{
		items[top++] = item;
		return true;
	}
	return false;
}

void List::visit(void (*pf) (Item& item))
{
	for (int i = 0; i < top; i++)
	{
		pf(items[i]);
	}
}

void visit_item(Item& item)
{
	std::cout << "Item = " << item << std::endl;
}

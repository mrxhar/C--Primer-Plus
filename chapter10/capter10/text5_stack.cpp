#include "text5_stack.h"
#include <iostream>
using namespace std;

Stack::Stack()
{
	top = 0;
}
bool Stack::isempty() const
{
	return top == 0;
}

bool Stack::isfull() const
{
	return top == Max;
}

bool Stack::push(Item& item) {
	if (isfull())
	{
		cout << "STACK IS FULL!" << endl;
		return false;
	}
	else
	{
		items[++top] = item;
		return true;
	}
}

bool Stack::pop(Item& item) {
	if (isempty())
	{
		cout << "STACK IS EMPTY!" << endl;
		return false;
	}
	else
	{
		item = items[top--];
		return true;
	}
}
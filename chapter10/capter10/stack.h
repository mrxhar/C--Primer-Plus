#ifndef __Stack__H__
#define __Stack__H__

typedef unsigned long Item;

class Stack
{
public:
	Stack();
	bool isempty() const;
	bool isfull() const;
	bool push(Item& item);
	bool pop(Item& item);

private:
	enum{MAX = 10};
	Item items[MAX];
	int top;
};

#endif // !__Stack__H__


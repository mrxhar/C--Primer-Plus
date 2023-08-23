#ifndef __STAKC__H__
#define __STAKC__H__

struct customer
{
	char fullname[35];
	double payment;
};

typedef customer Item;

class Stack
{
public:
	Stack();
	bool isempty() const;
	bool isfull() const;
	bool push(Item& item);
	bool pop(Item& item);
	
private:
	enum { Max = 10 };
	Item items[Max];
	int top;
};

#endif // !__STAKC__H__

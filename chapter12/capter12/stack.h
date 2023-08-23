#ifndef __Stack__H__
#define __Stack__H__

typedef unsigned long Item;

class Stack
{
public:
	Stack(int n = MAX);
	Stack(const Stack& st);
	~Stack();
	bool isempty() const;
	bool isfull() const;
	bool push(const Item& item);
	bool pop(Item& item);
	Stack& operator=(const Stack& Item);

private:
	enum{MAX = 10};
	Item* pitems;
	int size;
	int top;
};

#endif // !__Stack__H__


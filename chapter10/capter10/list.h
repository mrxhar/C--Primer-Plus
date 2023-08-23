#pragma once

typedef  unsigned long Item;

void visit_item(Item& item);

class List
{
private:
	static const int MAX = 10;
	Item items[MAX];
	int top;
public:
	List();
	bool isempty() const;
	bool is_full() const;
	bool add(const Item& item);
	void visit(void (*pf) (Item& item)); // ����ָ�룬���к����Ĳ���Ϊ Item& item
};


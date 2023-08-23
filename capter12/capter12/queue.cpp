
#include <iostream>
#include "queue.h"

Queue::Queue(int qs) : qsize(qs)
{
	front = rear = NULL;
	items = 0;
}

Queue::~Queue()
{
	Node* temp;
	while (front != NULL)
	{
		temp = front;
		front = front->next; // front 要依次向下释放空间，不止这个单独的 Node
		delete temp;
	}
}

bool Queue::isempty() const
{
	return items == 0;
}

bool Queue::isfull() const
{
	return items == qsize;
}

int Queue::queuecount() const
{
	return items;
}

bool Queue::enqueue(const Item& item)
{
	if (isfull())
	{
		return false;
	}
	Node* add = new Node;
	add->item = item;
	add->next = NULL;
	items++;
	if (front == NULL) // 当前的节点为空节点
	{
		front = add;
	}
	else
	{
		rear->next = add;
	}
	rear = add;
	return true;
}

bool Queue::dequeue(Item& item)
{
	if (front == NULL) // 空队列
	{
		return false;
	}
	item = front->item;
	items--;
	Node* temp = front; // 临时存储，方便释放空间
	front = front->next;
	delete temp;
	if (items == 0)
	{
		rear = NULL;
	}
	return true;
}

// Customer 接口的实现
void Customer::set(long when)
{
	processtime = std::rand() % 3 + 1;
	arrive = when;
}
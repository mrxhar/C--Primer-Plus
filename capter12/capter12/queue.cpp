
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
		front = front->next; // front Ҫ���������ͷſռ䣬��ֹ��������� Node
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
	if (front == NULL) // ��ǰ�Ľڵ�Ϊ�սڵ�
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
	if (front == NULL) // �ն���
	{
		return false;
	}
	item = front->item;
	items--;
	Node* temp = front; // ��ʱ�洢�������ͷſռ�
	front = front->next;
	delete temp;
	if (items == 0)
	{
		rear = NULL;
	}
	return true;
}

// Customer �ӿڵ�ʵ��
void Customer::set(long when)
{
	processtime = std::rand() % 3 + 1;
	arrive = when;
}
#ifndef QUEUE_H_
#define QUEUE_H_

class Customer
{
public:
	Customer() { arrive = processtime = 0; }

	void set(long when);
	long when() { return arrive; }
	int ptime() { return processtime; }

private:
	long arrive;
	int processtime;
};

typedef Customer Item;

class Queue
{
public:
	Queue(int qs = Q_SIZE);
	~Queue();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue(const Item& item);
	bool dequeue(Item& item); // ��ʱ�� item ����ɾ��ֵ

private:
	struct Node // �ṹ���������������ڲ���ֻ��������Ч
	{
		Item item;
		struct Node* next;
	};
	enum { Q_SIZE = 10 };

	Node* front;
	Node* rear; 
	int items;

	const int qsize;
	Queue(const Queue& q) :qsize(0) {} // ��Ա��ʼ���б�
	Queue& operator=(const Queue& q) { return *this; } // ��ֵ����
};

#endif // !QUEUE_H_


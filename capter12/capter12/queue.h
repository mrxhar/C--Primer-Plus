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
	bool dequeue(Item& item); // 这时候 item 接受删除值

private:
	struct Node // 结构定义在类声明的内部，只在类内生效
	{
		Item item;
		struct Node* next;
	};
	enum { Q_SIZE = 10 };

	Node* front;
	Node* rear; 
	int items;

	const int qsize;
	Queue(const Queue& q) :qsize(0) {} // 成员初始化列表
	Queue& operator=(const Queue& q) { return *this; } // 赋值函数
};

#endif // !QUEUE_H_


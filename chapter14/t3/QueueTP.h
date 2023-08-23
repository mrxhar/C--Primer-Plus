/*
@Author: mrxhar
@Date:   2023-08-22 16:39:41
@Email:  1337904145@qq.com
@Blog:
*/

#ifndef __QUEUETP__H__
#define __QUEUETP__H__

#include <iostream>
#include <string>

template <class T>
class QueueTP
{
private:
    struct Node
    {
        T item;
        struct Node *next;
    };

    enum
    {
        Q_SIZE = 10
    };

    Node *front;
    Node *rear;
    int items;
    const int qsize;
    QueueTP(const QueueTP &q) : qsize(0){};
    QueueTP &operator=(const QueueTP &q) { return *this; };

public:
    QueueTP(int qs = Q_SIZE);
    ~QueueTP();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const T &item);
    bool dequeue(T &item);
};

template <class T>
QueueTP<T>::QueueTP(int qs) : qsize(qs) // const 使用列表方式初始化
{
    items = 0;
    front = rear = NULL;
}

template <class T>
QueueTP<T>::~QueueTP()
{
    Node *temp;
    while (front != NULL)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
}

template <class T>
bool QueueTP<T>::isempty() const
{
    return items == 0;
}

template <class T>
bool QueueTP<T>::isfull() const
{
    return items == qsize;
}

template <class T>
int QueueTP<T>::queuecount() const
{
    return items;
}

template <class T>
bool QueueTP<T>::enqueue(const T &item)
{
    if (isfull())
    {
        std::cout << "Queue already full!\n";
        return false;
    }
    Node *newitem = new Node;
    newitem->item = item;
    newitem->next = NULL;
    items++;
    if (front == NULL)
    {
        front = newitem;
    }
    else
    {
        rear->next = newitem;
    }
    rear = newitem; // 末尾的标记
    return true;
}

template <class T>
bool QueueTP<T>::dequeue(T &item)
{
    if (isempty())
    {
        std::cout << "It's empty now!\n";
        return false;
    }
    item = front->item;
    items--;
    Node *temp = front; // 删除 front
    front = front->next;
    delete temp; // remove Node
    if (items == 0)
    {
        rear = NULL; // 末尾标记更新
    }
    return true;
}

class Worker
{
private:
    std::string fullname;
    long id;

public:
    Worker() : fullname("no one"), id(0L){};
    Worker(const std::string &s, long id) : fullname(s), id(id){};
    virtual ~Worker(){}; // 纯虚
    virtual void Set();
    virtual void Show() const;
};

void Worker::Set()
{
    std::cout << "Enter worker's name: ";
    getline(std::cin, fullname);
    std::cout << "Enter worker's id: ";
    std::cin >> id;
    while (std::cin.get() != '\n')
    {
        continue;
    }
}

void Worker::Show() const
{
    std::cout << "Name: " << fullname << std::endl;
    std::cout << "Employee's ID: " << id << std::endl;
}

#endif /* __QUEUETP__H__ */
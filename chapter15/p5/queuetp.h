/*
@Author: mrxhar
@Date:   2023-08-23 21:02:51
@Email:  1337904145@qq.com
@Blog:
*/

#ifndef __QUEUETP__H__
#define __QUEUETP__H__

template <class Item>
class QueueTP
{
private:
    enum
    {
        Q_size = 10
    };
    class Node
    {
    public:
        Item item;
        Node *next;
        Node(const Item &item) : item(item), next(nullptr){}; // 默认构造函数
    };
    Node *front;
    Node *rear;
    int items;
    const int qsize;
    QueueTP(const QueueTP &q) : qsize(0){};
    QueueTP &operator=(const QueueTP &q) { return *this; };

public:
    QueueTP(int qs = Q_size);
    ~QueueTP();
    bool isempty() const { return items == 0; };
    bool isfull() const { return items == qsize; };
    int queuecount() const { return items; };
    bool enqueue(const Item &item);
    bool dequeue(Item &item);
};

// 模板类的实现和声明在同一个头文件中
template <class Item>
QueueTP<Item>::QueueTP(int qs):qsize(qs)
{
    front = rear = nullptr;
    items = 0;
}

template <class Item>
QueueTP<Item>::~QueueTP()
{
    // 递归的消除每一个节点的指针
    Node *temp;
    while (front != nullptr)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
}

template <class Item>
bool QueueTP<Item>::enqueue(const Item &item)
{
    if (isfull())
    {
        return false;
    }
    Node *add = new Node(item);
    items++;
    if (front == nullptr)
    {
        front = add; // 空 队列 ，队首为当前添加进来的节点
    }
    else
    {
        rear->next = add; // 有字符串，对队尾需要调整
    }
    rear = add; // 队尾移动到当前的队尾
    return true;
}

template <class Item>
bool QueueTP<Item>::dequeue(Item &item)
{
    if (isempty())
    {
        return false;
    }
    items--;
    item = front->item; // 队首移出
    Node *temp = front; // 要删除front
    front = front->next;
    delete temp;
    if (items == 0) // 移除最后一个元素，回归空队列
    {
        rear = nullptr;
    }
    return true;
}

#endif

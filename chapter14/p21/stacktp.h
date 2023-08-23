/*
@Author: mrxhar
@Date:   2023-08-22 18:53:29
@Email:  1337904145@qq.com
@Blog:
*/
#ifndef __SRACKTP__H__
#define __SRACKTP__H__

template <class Type> // 方法实现在头文件
class Stack
{
private:
    enum
    {
        Max = 10
    };
    Type items[Max];
    int top;

public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Type &item);
    bool pop(Type &item);
};

template <class Type>
Stack<Type>::Stack()
{
    top = 0;
}

template <class Type>
bool Stack<Type>::isempty() const
{
    return (top == 0);
}

template <class Type>
bool Stack<Type>::isfull() const
{
    return (top == Max);
}

template <class Type>
bool Stack<Type>::push(const Type &item)
{
    if (top < Max)
    {
        items[top++] = item;
        return true;
    }
    else
    {
        return false;
    }
}

template <class Type>
bool Stack<Type>::pop(Type &item)
{
    if (top > 0)
    {
        item = items[--top];
        return true;
    }
    else
    {
        return false;
    }
}

#endif /* __SRACKTP__H__ */
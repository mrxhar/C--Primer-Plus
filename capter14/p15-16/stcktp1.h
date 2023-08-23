#ifndef __SRCKTP1__H__
#define __SRCKTP1__H__

template <class Type>
class Stack
{
private:
    enum
    {
        SIZE = 10
    };
    int stacksize;
    Type *items;
    int top;

public:
    explicit Stack(int ss = SIZE);
    Stack(const Stack &st);
    ~Stack() { delete[] items; };
    bool isempty() const { return top == 0; }
    bool isfull() const { return top == stacksize; }
    bool push(const Type &item);
    bool pop(Type &item);
    Stack &operator=(const Stack &st);
};

template <class Type>
Stack<Type>::Stack(int s) : stacksize(s), top(0)
{
    items = new Type[stacksize];
}

template <class Type>
Stack<Type>::Stack(const Stack &st)
{
    stacksize = st.stacksize;
    top = st.top;
    items = new Type[stacksize];
    for (int i = 0; i < top; i++)
    {
        items[i] = st.items[i];
    }
}

template <class Type>
bool Stack<Type>::push(const Type &item)
{
    if (top < stacksize)
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

template <class Type>
Stack<Type> &Stack<Type>::operator=(const Stack<Type> &st)
{
    if (this == &st)
    {
        return *this;
    }
    stacksize = st.stackSize;
    top = st.top;
    delete[] items;
    items = new Type[stacksize];
    for (int i = 0; i < top; i++)
    {
        items[i] = st.items[i];
    }

    return *this;
}

#endif /* __SRCKTP1__H__ */
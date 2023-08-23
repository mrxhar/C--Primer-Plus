/*
@Author: mrxhar
@Date:   2023-08-23 21:19:37
@Email:  1337904145@qq.com
@Blog:
*/
#include <iostream>

#include <string>
#include "queuetp.h"

int main()
{
    using std::cin;
    using std::cout;
    using std::string;

    QueueTP<string> cs(5);
    string temp;

    while (!cs.isfull())
    {
        cout << "Please enter your name. You will be served in the order of arrival.\n";
        cout << "name: ";
        getline(cin, temp);
        cs.enqueue(temp);
    }

    cout << "The queue is full. Processing begins.\n";
    while (!cs.isempty())
    {
        cs.dequeue(temp);
        cout << "Now Processing " << temp << "...\n";
    }

    return 0;
}

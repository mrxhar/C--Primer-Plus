// Queue.cpp -- check the functions and xlasses

#include <iostream>
#include <string>
#include "QueueTP.h"
using namespace std;

int main()
{
    QueueTP<Worker> *Qworker = new QueueTP<Worker>(20);
    Worker w1("Leonardo", 1024);
    Worker w2("Elma", 2035);
    if (Qworker->isempty())
    {
        cout << "Qworker is empty!\n";
    }
    Qworker->enqueue(w1);
    Qworker->enqueue(w2);
    cout << "Qworker count: " << Qworker->queuecount() << endl;
    Worker w3("hello", 2);
    Qworker->enqueue(w3);
    Qworker->enqueue(w2);
    cout << "Qworker count: " << Qworker->queuecount() << endl;
    Worker temp;
    Qworker->dequeue(temp);
    cout << "Dequeue: " << endl;
    temp.Show();
    Qworker->dequeue(temp);
    cout << "Dequeue: " << endl;
    temp.Show();
    cout << "Qworker count: " << Qworker->queuecount() << endl;
    system("pause");
    return 0;
}

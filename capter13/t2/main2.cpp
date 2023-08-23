#include <iostream>
using namespace std;
#include "classic2.h"

void Bravo(const Cd &disk);

int main()
{
    Cd c1("Beatless", "Capitol", 14, 35.5);
    Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);
    
    Cd *pcd = &c1;
    cout << "Using objects directly: " << endl;
    c1.Report();
    c2.Report(); // 应该报告 classic 的方法

    cout << "Using type cd* pointer to object:\n";
    pcd->Report();
    pcd = &c2;
    pcd->Report();

    cout << "Calling a function with a Cd reference argument: \n";
    Bravo(c1);
    Bravo(c2);

    cout << "Testing assignments: \n";
    Classic copy;
    copy = c2;
    copy.Report();
}

void Bravo(const Cd& disk)
{
    disk.Report();
}
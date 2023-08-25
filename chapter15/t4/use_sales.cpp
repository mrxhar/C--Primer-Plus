/*
@Author: mrxhar
@Date:   2023-08-24 16:39:26
@Email:  1337904145@qq.com
@Blog:
*/
#include <iostream>
#include "sales.h"

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    double vals1[12] = {
        1220, 1100, 1122, 2212, 1232, 2334,
        2884, 2393, 3302, 2922, 3002, 3544};

    double vals2[12] = {
        12, 11, 22, 21, 32, 34, 28, 29, 33, 29, 32, 35};

    Sales sales1{2011, vals1, 12};
    LabeledSales sales2("Blogstar", 2012, vals2, 12);

    cout << "First try block:\n";
    try
    {
        int i;
        cout << "Year = " << sales1.Year() << "\n";
        for (i = 0; i < 12; ++i) 
        {
            cout << sales1[i] << ' ';
            if (i % 6 == 5)
            {
                cout << endl;
            }
        }
        cout << "Year = " << sales2.Year() << endl; // 这个Year 调用基类的 Year函数
        cout << "Label = " << sales2.Label() << endl;
        for (i = 0; i <= 12; ++i) // 不出意外会超限一个 LabeledSales
        {
            cout << sales2[i] << ' '; 
            if (i % 6 == 5)
            {
                cout << endl;
            }
        }
        cout << "Enter of try block 1.\n";
    }
    catch (std::logic_error &bad) // 类的继承需要反向
    {
        if (LabeledSales::nbad_index *nbd = dynamic_cast<LabeledSales::nbad_index *>(&bad))
        {
            cout << nbd->what();
            cout << "Company: " << nbd->label_val() << endl;
            cout << "bad index: " << nbd->bi_val() << endl; // 基类的方法
        }

        else if (Sales::bad_index *bd = dynamic_cast<Sales::bad_index *>(&bad))
        {
            cout << bd->what();
            cout << "bad index: " << bd->bi_val() << endl;
        }
    }

    cout << "\nNext try block:\n";
    try
    {
        sales2[2] = 37.5;
        sales1[20] = 23345; // Sales
        cout << "Enter of try block 2.\n";
    }
    catch (std::logic_error &bad) // 类的继承需要反向
    {
        if (LabeledSales::nbad_index *nbd = dynamic_cast<LabeledSales::nbad_index *>(&bad))
        {
            cout << nbd->what();
            cout << "Company: " << nbd->label_val() << endl;
            cout << "bad index: " << nbd->bi_val() << endl; // 基类的方法
        }

        else if (Sales::bad_index *bd = dynamic_cast<Sales::bad_index *>(&bad))
        {
            cout << bd->what();
            cout << "bad index: " << bd->bi_val() << endl;
        }
    }
    cout << "Done.\n";
    return 0;
}
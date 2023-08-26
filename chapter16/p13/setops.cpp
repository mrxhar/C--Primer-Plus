/*
@Author: mrxhar
@Date:   2023-08-25 19:09:28
@Email:  1337904145@qq.com
@Blog:   
*/

#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>


int main(){
    using namespace std;

    const int N = 6;
    string s1[N] = {"buffoon", "thinkers", "for", "heavy", "can", "for"};
    string s2[N] = {"metal", "any", "food", "elegant", "deliver", "for"};

    set<string> A(s1,s1+N);
    set<string> B(s2,s2+N);

    ostream_iterator<string, char> out(cout, " ");
    cout << "Set A: ";
    copy(A.begin(), A.end(), out); //输出
    cout << "\Set B: ";
    copy(B.begin(), B.end(), out);
    cout << "\nUnion of A and B:\n";
    set_union(A.begin(), A.end(), B.begin(), B.end(), out);
    cout << "\nIntersection of A and B:\n";
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), out);
    cout << "\nDifference of A and B:\n";
    set_difference(A.begin(), A.end(), B.begin(), B.end(), out);
   
    cout << endl;

    set<string> C;
    cout << "\nSet C:\n";
    set_union(A.begin(), A.end(), B.begin(), B.end(), insert_iterator<set<string>>(C, C.begin()));
    
    copy(C.begin(), C.end(), out);

    string s3("grungy");
    C.insert(s3);
    cout << "Set C after insertion:\n";
    copy(C.begin(), C.end(), out);

    cout << "\nShowing a range:\n";
    copy(C.lower_bound("ghost"), C.upper_bound("spook"), out);
    cout << endl;

    return 0;
}
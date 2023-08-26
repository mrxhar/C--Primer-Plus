/*
@Author: mrxhar
@Date:   2023-08-26 10:03:07
@Email:  1337904145@qq.com
@Blog:   
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using std::vector;

vector<int> Lotto(int cnum, int rnum);
int main(){
    vector<int> winner;
    winner = Lotto(51, 6);
    std::cout << "Winner number: \n";
    for (auto it = winner.begin(); it != winner.end(); it++)
    {
        std::cout << *it << " ";
    }
    

    return 0;
}

vector<int> Lotto(int cnum, int rnum)
{
    vector<int> ticket(cnum);
    for (int i = 0; i < cnum; i++)
    {
        ticket[i] = i + 1;
    }
    random_shuffle(ticket.begin(), ticket.end());
    vector<int> choose(rnum);
    for (int i = 0; i < rnum; i++)
    {
        choose[i] = ticket[i];
    }
    sort(choose.begin(), choose.end());
    return choose;
}
/*
@Author: mrxhar
@Date:   2023-08-28 10:02:02
@Email:  1337904145@qq.com
@Blog:
*/

#include <iostream>
#include <fstream>
#include <string>

#include <vector>
#include <algorithm>

using namespace std;

void ShowStr(string &str);
void GetStrs(istream &is, vector<string> &vstr);

class Store
{
public:
    ostream &os;
    Store(ostream &os) : os(os) {}
    void operator()(const string &str);
};

int main()
{
    vector<string> vostr;
    string temp;

    cout << "Enter string (empty line to quit): \n";
    while (getline(cin, temp) && temp[0] != '\0')
    {
        vostr.push_back(temp);
    }

    cout << "Here is your input: \n";
    for_each(vostr.begin(), vostr.end(), ShowStr);

    ofstream fout("strings.dat", ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();

    vector<string> vistr;
    ifstream fin("strings.dat", ios_base::in | ios_base::binary);
    if (!fin.is_open())
    {
        cerr << "Could not open file\n";
        exit(EXIT_FAILURE);
    }
    GetStrs(fin, vistr);
    cout << "\nHere is your output: \n";
    for_each(vistr.begin(), vistr.end(), ShowStr);

    return 0;
}

void ShowStr(string &str)
{
    cout << str << endl;
}

void Store::operator()(const string &str)
{
    // 获取字符串长度
    size_t len = str.length();
    // 将字符串长度写入流
    os.write((char *)&len, sizeof(size_t)); // 存入长度，我们才能知道读取到哪里
    // 将字符串写入流
    os.write(str.data(), len);
}

void GetStrs(istream &is, vector<string> &vstr)
{
    string temp;
    size_t len;
    while (is.read((char *)&len, sizeof(size_t)) && len > 0)
    {
        char ch;
        temp = "";
        for (int i = 0; i < len; i++)
        {
            if (is.read(&ch, 1))
            {
                temp += ch;
            }
            else
            {
                break;
            }
        }
        if (is)
        {
            vstr.push_back(temp);
        }
    }
}

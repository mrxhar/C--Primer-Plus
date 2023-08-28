/*
@Author: mrxhar
@Date:   2023-08-28 08:08:41
@Email:  1337904145@qq.com
@Blog:
*/

#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::string;

int main(int argc, char *argv[])
{

    std::ofstream fout;

    for (int file = 0; file < argc; file++)
    {
        fout.open(argv[file]);
        if (!fout.is_open())
        {
            std::cerr << "Can't open " << argv[file] << std::endl;
            exit(EXIT_FAILURE);
        }
        cout << "Please enter the data to be written to the file(enter a vblank line to quit): ";
        string input;
        while (getline(std::cin, input) && input.size() > 0)
        {
            fout << input << "\n";
        }
        cout << "Input over\n";
        fout.close();
    }

    return 0;
}

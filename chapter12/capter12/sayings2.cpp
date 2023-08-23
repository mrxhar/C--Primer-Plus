#include <iostream>
#include <cstdlib>
#include <ctime>
#include "string1.h"


const int ArSize = 10;
const int MaxLen = 81;

int main()
{
	using namespace std;

	String name;

	cout << "Hi, what's your name?\n >> ";
	cin >> name;

	cout << name << ", please enter up to " << ArSize << " short sayings "
		<< "<empty line to quit>:\n";

	String sayings[ArSize];
	char temp[MaxLen];

	int i;
	for (i = 0; i < ArSize; i++)
	{
		cout << i + 1 << ": ";
		cin.get(temp, MaxLen);
		while (cin && cin.get() != '\n')
		{
			continue;
		}
		if (!cin || temp[0] == '\0')
		{
			break;
		}
		else
		{
			sayings[i] = temp; // 赋值运算符
		}
	}

	int total = i;
	
	if (total > 0)
	{
		cout << "Here are your sayings:\n";
		for (i = 0; i < total; i++)
		{
			cout << sayings[i] << endl;
		}

		String* shortest = &sayings[0];
		String* first = &sayings[0];

		for (i = 1; i < total; i++)
		{
			if (sayings[i].length() < shortest->length())
			{
				shortest = &sayings[i];
			}
			if (sayings[i] < *first)
			{
				first = &sayings[i];
			}
		}

		cout << "Shortest saying:\n" << *shortest << endl;
		cout << "First alphabetically:\n" << *first << endl;
		srand(time(0));
		int choice = rand() % total;
		String* favorite = new String(sayings[choice]); // 新的 String* 对象 并且这个指针指向了一个由 sayings[choice] 创建的新的String对象
		cout << "My favorite saying:\n" << *favorite << endl;
		delete favorite; 

	}
	else
	{
		cout << "No input! Bye.\n";
	}
	return 0;
}
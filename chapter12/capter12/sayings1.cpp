#include <iostream>
#include "string1.h"

const int ArSize = 10;
const int MaxLen = 81;

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	String name; // Ĭ�Ϲ��캯��
	cout << "Hi, what's your name?\n";
	cin >> name; 

	cout << name << ", please enter up to " << ArSize << " short saying <"
		"empty line to quit>:\n";
	
	String saying[ArSize]; // ����
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
			// ���� 
			break;
		}
		else
		{
			saying[i] = temp;
		}
	}

	int total = i;

	if (total > 0)
	{
		cout << "Here are your sayings:\n";
		for (i = 0; i < total; i++)
		{
			cout << saying[i][0] << ": " << saying[i] << endl;
		}
		
		int shortest = 0;
		int first = 0;

		for (i = 1; i < total; i++)
		{
			if (saying[i].length() < saying[shortest].length())
			{
				shortest = i;
			}
			if (saying[i] < saying[first])
			{
				first = i;
			}
		}

		cout << "Shortest saying:\n" << saying[shortest] << endl;
		cout << "First saying:\n" << saying[first] << endl;
		cout << "This program used " << String::HowMany() << " String objects."
			"Bye.\n";
	}
	else
	{
		cout << "No input! Bye.\n";
	}
	return 0;
}
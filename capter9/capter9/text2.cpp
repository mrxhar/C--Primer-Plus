#include <iostream>
#include <string>

using namespace std;

const int ArSize = 10;

void strcount(const string str);
int main(void)
{
	string input;

	cout << "Enter a line: " << endl;
	getline(cin, input);

	while (input != "")
	{
		strcount(input);
		cout << "Enter next line (empty line to quit): " << endl;
		getline(cin, input);
	}
	cout << "ByeBye!\n";
	return 0;
}

void strcount(const string str) {
	static int total = 0;
	int count = str.size();
	
	total += count;
	cout << count << " characters" << endl;
	cout << total << " characters total " << endl;
}

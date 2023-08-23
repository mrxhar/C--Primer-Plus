#include "p2.h"

Person::Person(const string& ln, const char* fn)
{
	lname = ln;
	strcpy_s(fname, fn);
}

void Person::show() const
{
	if (lname == "" && fname[0] == '\0')
		cout << "No name!" << endl;
	else
		cout << "Person name: " << fname << " " << lname << endl;
}

void Person::FarmalShow() const
{
	if (lname == "" && fname[0] == '\0')
		cout << "No name!" << endl;
	else
		cout << "Person name: " << lname << " " << fname << endl;
}
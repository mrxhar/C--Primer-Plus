#ifndef __P2__H__
#define __P2__H__

#include <iostream>

using namespace std;

class Person
{
public:
	Person() { lname = "", fname[0] = '\0'; };
	Person(const string& ln, const char* fn = "Heyyou");

	void show() const;
	void FarmalShow() const;
private:
	static const int LIMIT = 25;
	string lname;
	char fname[LIMIT];
};

#endif // !__P2__H__


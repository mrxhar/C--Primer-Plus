#include <iostream>
#include "cow.h"
#include <string>

using std::cout;
using std::endl;


Cow::Cow() {
	strcpy_s(name,20 ,"new cow");
	hobby = new char[4];
	strcpy_s(hobby,4, "cow");
	weight = 0.0;
}

Cow::Cow(const char* nm, const char* ho, double wt)
{
	strcpy_s(name,20, nm); 
	// ÐÂµÄ¿Õ¼ä
	hobby = new char[strlen(ho) + 1];
	strcpy_s(hobby, (strlen(ho) + 1), ho);
	weight = wt;
}

Cow::Cow(const Cow& c)
{
	strcpy_s(name, 20, c.name);
	hobby = new char[strlen(c.hobby) + 1];
	strcpy_s(hobby, (strlen(c.hobby) + 1), c.hobby);
	weight = c.weight;
}


Cow::~Cow() {
	delete[] hobby;
}

Cow& Cow::operator=(const Cow& c)
{
	if (this == &c)
	{
		return *this;
	}
	delete[] hobby;
	hobby = new char[strlen(c.hobby) + 1];
	strcpy_s(hobby, strlen(c.hobby) + 1, c.hobby);
	weight = c.weight;
	strcpy_s(name, c.name);
}

void Cow::ShowCow() const {
	cout << this << name << "'s hobby is " << hobby << ", weight is " << weight 
		<< endl;
}
#include "p2.h"
#include <iostream>

int main(void)
{
	Person one;
	Person two("Rick");
	Person three("Micheal","Jackson");

	one.show();
	one.FarmalShow();
	cout << endl;

	two.show();
	two.FarmalShow();
	cout << endl;

	three.show();
	three.FarmalShow();
	cout << endl;
}
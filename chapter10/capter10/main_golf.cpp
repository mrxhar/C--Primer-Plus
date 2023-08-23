#include <iostream>
#include "golf.h"

using namespace std;

int main(void) {
	golf p1("Rick", 100);
	golf p2;

	cout << endl;
	cout << "Now show two Person:" << endl;
	p1.showgolf();
	p2.showgolf();
}
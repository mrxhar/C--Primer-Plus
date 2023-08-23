

#include "cow.h"

int main() {
	Cow c;
	c.ShowCow();
	Cow c1("Cow","1234", 10);
	c1.ShowCow();

	Cow c2 = c1;
	c2.ShowCow();

	Cow c3;
	c3 = Cow(c1);
	c3.ShowCow();

	return 0;
}
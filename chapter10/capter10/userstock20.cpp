#include<iostream>
#include"stock20.h"

int main(void) {
	using std::cout;
	cout << "Using constructors to create new objects\n";
	Stock stock1("Nanosmart", 12, 20.0);
	stock1.show();
	Stock stock2 = Stock("Boffo objects", 2, 2.0);
	stock2.show();
	
	Stock top = stock1.topval(stock2);
	cout << "\nNow show the top val:\n";
	top.show();

	return 0;
}
#include<iostream>
#include"stock.h"

int main(void) {
	using std::cout;
	cout << "Using constructors to create new objects\n";
	Stock stock1("Nanosmart", 12, 20.0);
	cout << stock1;
	Stock stock2 = Stock("Boffo objects", 2, 2.0);
	cout << stock2;

	cout << "Assigning stock1 to stock2:\n";
	stock2 = stock1;
	cout << "Listing stock1 and stock2:\n";
	cout << stock1;
	cout << stock2;


	cout << "Using a constructors to reset an object\n";
	stock1 = Stock("Nifty Foods", 10, 50.0); // 将构造函数构造的类对象赋值给stock1，效率较慢 // 还有一个等式
	cout << "Revise stock1:\n";
	cout << stock1;
	cout << "Done!\n";

	const Stock stock3("NanoSmart9", 20, 12.50);
	cout << stock3;
	/*Stock stock1;
	stock1.show();*/
	/*stock1 = Stock("NanoSmart", 20, 12.50);
;	stock1.show();
	stock1.buy(15, 18.125);
	stock1.show();
	stock1.sell(400, 20.00);
	stock1.show();
	stock1.buy(300000, 40.125);
	stock1.show();
	stock1.sell(300000, 0.125);
	stock1.show();*/



	return 0;
}
#include <iostream>
#include <new>

using namespace std;

const int BUF = 512;
const int N = 5;
char buffer[BUF];

int main(void)
{
	double* pd1, * pd2;
	int i;
	cout << "Calling new and placement new: " << endl;
	pd1 = new double[N];
	pd2 = new(buffer) double[N];

	for (i = 0; i < N; i++)
	{
		pd2[i] = pd1[i] = 1000 + 20.0 * i;
	}
	cout << "pd1 = " << pd1 << ", buffer = " << (void*)buffer << endl;
	for (i = 0; i < N; i++)
	{
		cout << pd1[i] << " at " << &pd1[i] << "; ";
		cout << pd2[i] << " at " << &pd2[i] << "\n";
 	}


	cout << "\nCalling new and placement new a second time: " << endl;
	double* pd3, * pd4;
	pd3 = new double[N];
	pd4 = new (buffer) double[N];
	for (i = 0; i < N; i++)
	{
		pd4[i] = pd3[i] = 1000 + 40.0 * i;
	}
	for (i = 0; i < N; i++)
	{
		cout << pd3[i] << " at " << &pd3[i] << "; ";
		cout << pd4[i] << " at " << &pd4[i] << "\n";
	}

	cout << "\nCalling new and placement new a third time: " << endl;
	delete[] pd1;
	pd1 = new double[N];
	pd2 = new(buffer + N * sizeof(double)) double[N];
	for (i = 0; i < N; i++)
	{
		pd2[i] = pd1[i] = 1000 + 60.0 * i;
	}
	for (i = 0; i < N; i++)
	{
		cout << pd1[i] << " at " << &pd1[i] << "; ";
		cout << pd2[i] << " at " << &pd2[i] << "\n";
	}
	delete[] pd1;
	delete[] pd3; // delete 动态内存空间内部 定位 new 开辟的是静态运算符
	return 0;
}
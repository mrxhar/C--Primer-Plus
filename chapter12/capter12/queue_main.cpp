#include <iostream>
#include <cstdlib>
#include "queue.h"

const int MIN_PER_HR = 60;

bool newcustomer(double);

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	using std::ios_base;

	std::srand(std::time(0));

	cout << "Case Study: Bank of Heather Automatic Teller\n";
	cout << "Enter maximum size of queue: ";

	int qs;
	cin >> qs;
	Queue line(qs);

	cout << "Enter the number of simulation hours: ";
	int hours;
	cin >> hours;

	long cyclelimit = MIN_PER_HR * hours;


	double perhour = 1;

	double min_per_cust;
	min_per_cust = MIN_PER_HR / perhour;

	Item temp;

	long turnaways = 0;
	long customers = 0;
	long served = 0;
	long sum_line = 0;
	int wait_time = 0;
	long line_wait = 0;

	double avetime = 0;
	while (avetime < 1)
	{
		perhour++;
		while (!line.isempty())
		{
			line.dequeue(temp);
		}
		min_per_cust = MIN_PER_HR / perhour;


		for (int cycle = 0; cycle < cyclelimit; cycle++)
		{
			//cout << newcustomer(min_per_cust) << endl;
			if (newcustomer(min_per_cust)) // 随机顾客来袭 约 min_per_cust 小时一个
			{
				if (line.isfull())
				{
					turnaways++; // 等待 等待顾客数目
				}
				else // 进队列
				{
					customers++;
					temp.set(cycle); // cycle 时刻来
					line.enqueue(temp); // 添加进 line
				}
			}
			if (wait_time <= 0 && !line.isempty()) // 出队列
			{
				line.dequeue(temp);
				wait_time = temp.ptime(); // 队首开始办理业务
				//cout << cycle <<" :   " << wait_time << endl;
				line_wait += cycle - temp.when(); // 队伍等待时间
				served++; // 服务人数
			}
			if (wait_time > 0)
			{
				wait_time--;
			}
			sum_line += line.queuecount();
		}
		if (customers > 0)
		{
			cout << "customers accepted: " << customers << endl;
			cout << "  customers served: " << served << endl;
			cout << "          turnways: " << turnaways << endl;
			cout << "average queue size: ";
			cout.precision(2);
			cout.setf(ios_base::fixed, ios_base::floatfield);
			cout << (double)sum_line / cyclelimit << endl;
			cout << " average wait time: " << (double)line_wait / served
				<< " minutes\n";
			cout << "\n\n";
		}
		else
		{
			cout << "No customers!\n";
		}
		avetime = (double)line_wait / served;

	}
	cout << "When there comes " << perhour << " people per hour, the average wait time will be about 1 minutes.\n";
	cout << "Done!\n";
	return 0;
}

bool newcustomer(double x) {
	return (std::rand() * x / RAND_MAX < 1);
}
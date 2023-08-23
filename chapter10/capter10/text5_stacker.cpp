#include <iostream>
#include "text5_stack.h"
//#include <cctype>

int main()
{
	char ch;
	customer cust;
	Stack st;
	double sum = 0.0;

	std::cout << "Please enter A to push to stack,\n"
		<< "P to pop from stack, Q to quit.\n";

	while (std::cin >> ch && toupper(ch) != 'Q')
	{
		while (std::cin.get() != '\n')
		{
			continue;
		}
		switch (ch)
		{
		case 'A':
		case 'a':
			std::cout << "Enter a customer's fullname you want to push to stack:\n";
			std::cin.getline(cust.fullname, 35);
			std::cout<< "Enter a customer's payment:\n";
			std::cin >> cust.payment;

			if (st.isfull())
			{
				std::cout << "Satck already full\n";
			}
			else
			{
				st.push(cust);
			}
			break;
		case 'P':
		case 'p':
			if (st.isempty())
			{
				std::cout << "Satck is empty\n";
			}
			else
			{
				st.pop(cust);
				sum += cust.payment;
				std::cout << cust.fullname << " " << cust.payment << " is poped\n";
				std::cout << "sum payment " << sum << std::endl;
			}
			break;
		default:
			break;
		}
		std::cout << "Please enter A to push to stack,\n"
			<< "P to pop from stack, Q to quit.\n";
	}

	return 0;
}
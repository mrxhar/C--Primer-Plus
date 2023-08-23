#include <iostream>
#include "stack.h"
//#include <cctype>

int main()
{
	char ch;
	unsigned long po;
	Stack st;

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
			std::cout << "Enter a number you want to push to stack:\n";
			std::cin >> po;
			if (st.isfull())
			{
				std::cout << "Satck already full\n";
			}
			else
			{
				st.push(po);
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
				st.pop(po);
				std::cout << po << " is poped\n";
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
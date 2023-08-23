#include <iostream>
#include "golf.h"

using namespace std;

const int SIZE = 2;

int main(void)
{
	golf g[SIZE];
	int count = 0;

	cout << "Please enter the information of golf players: \n";
	
	while ((count < SIZE) && (setgolf(g[count])))
	{
		if (++count < SIZE) {
			cout << "Please enter next player: " << endl;
		}
	}
	cout << "\nShow all golf players informations:";
	for (int i = 0; i < count; i++)
	{
		showgolf(g[i]);
	}

	cout << "\nReset all the players information: " << endl;
	for (int i = 0; i < count; i++)
	{
		handicap(g[i], 90);
		showgolf(g[i]);
	}

	return 0;
}
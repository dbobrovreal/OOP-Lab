#include "menu.h"
#include <cstdlib>

int main()
{ 
	Terminal terminal;
	int flag;

	while (flag != 6) {
		terminal.menu();
		cout << "Action number: ";
		cin >> flag;
		system("clear");
		terminal.act(flag);
	}

	//test();

	return 0;
}
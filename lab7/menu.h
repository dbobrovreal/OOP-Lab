#ifndef MENU_H
#define MENU_H

#include "Table.h"

class Terminal
{
	Table test;
public:
	void menu();
	void act(int);
};

void Terminal::menu()
{
	cout << endl << "1) List of products" << endl;
	cout << "2) Product search" << endl;
	cout << "3) Addition of products" << endl;
	cout << "4) Purchase of products" << endl;
	cout << "5) Save table" << endl;
	cout << "6) Exit" << endl;
}

void Terminal::act(int act)
{
	string value;
	int price;
	switch (act)
	{
		case 1:
			test.get_table();
			break;
		case 2:
			cout << "Input product: ";
			cin >> value;
			test.search_product(value);
			break;
		case 3:
			cout << "Input name product: ";
			cin >> value;
			cout << "Input price product: ";
			cin >> price;
			test.add_element(value, price);
			break;
		case 4:
			cout << "Input name product for purches: ";
			cin >> value;
			test.delete_element(value);
			break;
		case 5:
			test.save_table();
			break;
		case 6:
			break;
		default:
			cout << "Error, action does not exist, try again" << endl;
			break;
	}
}

#endif
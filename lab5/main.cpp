#include <iostream>
#include "stack.h"
#include "queu.h"

int main()
{
	Stack stack;
	Queu queu;
	int line;

	cout << "Input line stack and queu: ";
	cin >> line;
	cout << endl;

	for (int i = 0; i < line; ++i)
	{
		stack.add_element(i);
		queu.add_element(i);
	}
	for(int i = 0; i < line; ++i){
		stack.print();
		stack.delete_element();
	}

	for(int i = 0; i < line; ++i){
		queu.print();
		queu.delete_element();
	}

	return 0;
}
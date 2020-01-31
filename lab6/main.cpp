#include <iostream>
#include "Vector.h"

using namespace std;

int main (int argc, char *argv[]) {
	Vector<string> arr(12);
	string std;
	short int key1, key2, key3, key4;
	int k;
	printf("1) Input element\n");
	printf("0) Exit\n");
	cin >> key1;
	switch(key1)
	{
		case 1:
		{
			printf("How many items to add? ");
			cin >> k;
			for (int i = 1; i <= k; ++i)
			{
				printf("Element %i: ", i);
				cin >> std;
				arr.add_element(std.substr(0, 4), i);
			}
		}

		case 0:
		{
			arr.print();
		}
	}
	printf("1) Delete element\n");
	printf("0) Exit\n");
	cin >> key2;
	switch(key2)
	{
		case 1:
		{
			int elem;
			printf("Which item to remove?\n");
			cin >> elem;
			if (elem <= k){
				arr.delete_element(elem);
			}else{
				printf("Error\n");
				return 0;
			}
		}
		case 0:
		{
			arr.print();
		}
	};
	printf("1) Item replacement\n");
	printf("0) Exit\n");
	cin >> key3;
	switch(key3)
	{
		case 1:
		{	
			int h;
			printf("Element: \n");
			cin >> std;
			printf("Item number\n");
			cin >> h;
			arr.add_element(std.substr(0,4), h);
		}
		
		case 0:
		{
			arr.print();
		}
	}
	printf("1) Lookup element\n");
	printf("0) Exit\n");
	cin >> key4;
	switch(key4)
	{
		case 1:
		{
			int lookup_elem;
			printf("Item number\n");
			cin >> lookup_elem;
			printf("Element: ");
			cout << arr.lookup_element(lookup_elem) << endl;
		}
		case 0:
		{
			return 0;
		}
	}

	return 0;
}
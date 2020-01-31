#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void free_2D_arr(int size, int **arr)
{
	for (int i; i < size; i++){
		delete []arr[i];
	}
}

void print_2D_arr(int size, int **arr)
{
	for (int row = 0; row < size; row++){
		for (int column = 0; column < size; column++){
			cout << arr[row][column] << '\t';
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	srand(time(0));
	int size = rand() % 10 + 2;
	int **arr = new int* [size];

	for (int column = 0; column < size; column++) {
		arr[column] = new int [size];
	}

	for (int row = 0; row < size; row++){
		for (int column = 0; column < size; column++){
			arr[row][column] = rand() % 100;
		}
	}

	print_2D_arr(size, arr);

	return 0;
}
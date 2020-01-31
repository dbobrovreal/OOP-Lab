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

void free_1D_arr(int *arr)
{
	delete []arr;
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

void print_1D_arr(int size, int *arr)
{
	for (int i = 0; i < size * size; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	srand(time(0));
	int size = 6;
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

//№1
	cout << "№1" << endl;
	int *arr_a = new int [size * size];
	int i = 0;

	for (int column = 0; column < size; column++){
		int column_stop = column;
		for (int row = 0; row <= column; row++) {
			arr_a[i] = arr[row][column_stop];
			i++;
			column_stop--;
		}

	}

	for (int row = 1; row < size; row++){
		int row_stop = row;
		for (int column = size - 1; column >= row; column--){
			arr_a[i] = arr[row_stop][column];
			i++;
			row_stop++;
		}
	}

	print_1D_arr(size, arr_a);
	free_1D_arr(arr_a);
//№1 end

//№2
	cout << "№2" << endl;
	int *arr_b = new int [size * size];
	i = 0;

	for (int column = size - 1; column >= 0; column--){
		int column_stop = column;
		for (int row = 0; row < size - column; row++) {
			arr_b[i] = arr[row][column_stop];
			i++;
			column_stop++;
		}

	}

	for (int row = 1; row < size; row++){
		int row_stop = row;
		for (int column = 0; column < size - row; column++){
			arr_b[i] = arr[row_stop][column];
			i++;
			row_stop++;
		}
	}

	print_1D_arr(size, arr_b);
	free_1D_arr(arr_b);
//№2 end
/*
//№3
	cout << "№3" << endl;
	int *arr_c = new int [size];
	int row = size / 2, column = size / 2 - 1;
	int size_row = size - 1, size_col = size - 1;
	//cout << "size " << size << endl;
	i = 0;

	for (;i != size * size - 1;) {
		for (int j = 0; j < size - size_col && i != size * size - 1; j++, i++, column++) {
			arr_c[i] = arr[row][column];
			//cout << arr_c[i] << " - ";
			//cout << row << " " << column << endl;
		}
		size_col--;
		//cout << "row " << row << " column " << column << endl;
		//cout << "size_row " << size_row << " size_col " << size_col << endl;

		for (int j = 0; j < size - size_row && i != size * size - 1; j++, i++, row--) {
			arr_c[i] = arr[row][column];
			//cout << arr_c[i] << " - ";
			//cout << row << " " << column << endl;
		}
		size_row--;
		//cout << "row " << row << " column " << column << endl;
		//cout << "size_row " << size_row << " size_col " << size_col << endl;

		for (int j = 0; j < size - size_col && i != size * size - 1; j++, i++, column--) {
			arr_c[i] = arr[row][column];
			//cout << arr_c[i] << " - ";
			//cout << row << " " << column << endl;
		}
		size_col--;
		if (i == size * size - 1) {
			arr_c[i] = arr[row][column];
		}
		//cout << "row " << row << " column " << column << endl;
		//cout << "size_row " << size_row << " size_col " << size_col << endl;
		//cout << i << endl;

		for (int j = 0; j < size - size_row && i != size * size - 1; j++, i++, row++) {
			arr_c[i] = arr[row][column];
			//cout << arr_c[i] << " - ";
			//cout << row << " " << column << endl;
		}
		size_row--;
		//cout << "row " << row << " column " << column << endl;
		//cout << "size_row " << size_row << " size_col " << size_col << endl;
		//return 0;
	}

	print_1D_arr(size, arr_c);
	free_1D_arr(arr_c);
//№3 end
*/
//test 4
	cout << "№4" << endl;
	int *arr_d = new int [size * size];
	int row_d = 0, column_d = 0, size_row_d = 1, size_col_d = 0;
	i = 0;

	for (;i != size * size - 1;) {
		for (int j = size_col_d; j < size && i != size * size - 1; j++, i++, column_d++) {
			arr_d[i] = arr[row_d][column_d];
			//cout <<	arr_d[i] << " ";
			//cout << row << column << " ";
			//cout << j << " ";
			//cout << i << endl;
		}
		//cout << row << column << endl;
		column_d--;
		row_d++;
		size_col_d++;
		//cout << row << column << endl;

		for (int j = size_row_d; j < size && i != size * size - 1; j++, i++, row_d++) {
			arr_d[i] = arr[row_d][column_d];
			//cout <<	arr_d[i] << " ";
			//cout << row << column << " ";
			//cout << j << " ";
			//cout << i << endl;
		}
		//cout << row << column << endl;
		row_d--;
		column_d--;
		size_row_d++;
		//cout << row << column << size_row << size_col  << i << endl;

		if (i == size * size - 1) {//костыль
			//cout << i << endl;
			arr_d[i] = arr[row_d][column_d];
			//cout <<	arr_d[i] << " ";
			//cout << i << endl;
		}

		for (int j = size_col_d; size - j > 0 && i != size * size - 1; j++, i++, column_d--) {
			//cout << "test";
			arr_d[i] = arr[row_d][column_d];
			//cout <<	arr_d[i] << " ";
			//cout << row << column << " ";
			//cout << i << endl;
		}
		//cout << row << column << endl;
		column_d++;
		row_d--;
		size_col_d++;
		//cout << row << column << endl;

		for (int j = size_row_d; size - j > 0 && i != size * size - 1; j++, i++, row_d--) {
			arr_d[i] = arr[row_d][column_d];
			//cout <<	arr_d[i] << " ";
			//cout << row << column << " ";
			//cout << i << endl;
		}
		//cout << row << column << endl;
		column_d++;
		row_d++;
		size_row_d++;
		//cout << row << column << endl;
	}
	print_1D_arr(size, arr_d);
	free_1D_arr(arr_d);
//test 4


	free_2D_arr(size, arr);

	return 0;
}
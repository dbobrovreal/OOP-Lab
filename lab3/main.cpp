#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class Table
{
	int row;
	int column;
	int **arr;
public:
	Table()
	{
		row = 0;
		column = -1;
	}
	/*void table_init();
	void set_random_table();
	void get_table();
	void get_row();
	void get_column();
	void save_table();
	void input_table();*/

	void table_init() {
		arr = new int* [row];
		for (int i = 0; i < column; i++) {
			arr[i] = new int [column];
		}
	}

	void set_random_table()
	{
		row = 5;
		column = 5;
		table_init();
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				arr[i][j] = rand() % 10;
			}
		}
	}

	void get_table()
	{
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}
	}

	void get_row()
	{
		cout << "Row: " << row << endl;
	}

	void get_column()
	{
		cout << "Column: " << column << endl;
	}

	void save_table()
	{
		ofstream file;
		file.open("Table.txt");
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				file << arr[i][j] << "\t";
			}
			if (i != row - 1) {
				file << endl;
			}
		}
		file.close();
	}

	void input_table()
	{
		ifstream file;
		int column_t = 0, z = 0;
		const char *str;
		string buf;

		file.open("Table.txt");
		while (!file.eof()) {
			getline(file, buf);
			str = buf.c_str();
			column_t = 0;
			for (int i = 0; str[i] != 0; i++) {
				if (str[i] == '\t') {
					column_t++;	
				}
				if (column_t > column) {
					column = column_t;
				}
			}
			row++;
		}

		file.seekg(0, ios::beg);
		file.clear();

		table_init();
		for (int i = 0; i < row; i++) {
			getline(file, buf);
			str = buf.c_str();
			for (int j = 0; str[j] != 0 && z < column; j++) {
				if (str[j] == '\t') {
					continue;
				}
				file >> buf;
				cout << buf << endl;
				//arr[i][z] = str[j];
				z++;
			}
		}

		file.close();
	}
};
int main()
{
	int number;
	cout << "Input number of table: ";
	cin >> number;
	cout << endl;
	Table *tab = new Table[number];

	for (int i = 0; i < number; i++) {
		tab[i].set_random_table();
	}

	for (int i = 0; i < number; ++i)
	{
		tab[i].get_row();
		tab[i].get_column();
		tab[i].get_table();
	}

	tab[0].save_table();

	tab[0].input_table();

	return 0;
}
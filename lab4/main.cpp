#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Menu
{
	string text;
public:
	/*void open_file_string();0
	void input_string();
	void output_string();
	void search_string(string);
	void search_delete_string(string);
	void delete_string();
	void save_file_string();*/


	void open_file_string() //Открыть файл
	{
		string str;
		ifstream file;
		file.open("save_string.txt");
		file >> str;
		text = str;
		file.close();
	}

	void input_string() //Ввести строку
	{
		string str;
		cout << "Input string: ";
		cin >> str;
		text += str;
	}

	void output_string()//Показать текст
	{
		cout << text << endl;
	}

	void search_string(string str)//Поиск слов
	{
		int h = 0;
		for (int i = 0; i < (int)text.length(); i++){
			if (str == text.substr(i, str.length())){
				cout << text.substr(i, str.length()) << endl;
				h ++;
			}
		}
		if (h == 0){
			printf("No slovo.\n");
		}
	}

	void search_delete_string(string str)//Удаление слова
	{
		int k;
		while((k = text.find(str)) != -1){
			text.erase(k, str.length());
		}	
	}

	void delete_string()//очистить терминал
	{
		text.clear();
	}

	void save_file_string()//Cохранить 
	{
		string name;
		ofstream file;
		cout << "File name:" << endl;
		cin >> name;
		file.open(name);
		file << text;
		file.close();
	}
};

int main()
{

	string str;
 	short int key_1, key_2, key_3, key_4;
	Menu text;
	text.open_file_string();
	text.output_string();
	printf("1) input_string\n");
	printf("0) no input_string\n");
	cin >> key_1;
	switch (key_1)
	{
		case 1:
		{
			text.input_string();
			break;
		}
		case 0:
		{
			text.output_string();
			break;
		}
	}
	text.output_string();
	printf("1) Search string\n");
	printf("0) No search string\n");
	cin >> key_2;
	switch (key_2){
		case 1:{
			cout << "Search string: ";
			cin >>str;
			text.search_string(str.substr(0, 4));
			break;
		}
		case 0:
		{
			text.output_string();
			break;	
		}
	}
	printf("1) Delet_string\n");
	printf("0) no Delet_string\n");
	cin >> key_3;
	switch (key_3)
	{
		case 1:
		{
			cout << "Delet:"<<endl;
			cin >> str;
			text.search_delete_string(str.substr(0, 4));
			break;
		}
		case 0:
		{
			text.output_string();
			break;		
		}
	}
	text.output_string();
	printf("1) Save file\n");
	printf("0) no save file\n");
	cin >> key_4;
	switch (key_4)
	{
		case 1:
		{
			text.save_file_string();
			break;	
		}
		case 0:
		{
			text.output_string();
			break;
		}
	}
	text.delete_string();
	text.output_string();

	return 0;
}
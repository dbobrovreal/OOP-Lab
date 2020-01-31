#ifndef TABLE_H
#define TABLE_H

#include "set.h"
#include <fstream>

class Table: public Set
{
public:
	void get_table();
	void input_table();
	void save_table();
	Node* create_node(Node*, Node*);
	void add_element(string, int);
	void search_product(string);
	Node* lookup_element(string);
	void print_set();
	void delete_element(string);
};

void Table::get_table()
{
	if (set == NULL) {
		input_table();
	}
	print_set();
}

void Table::input_table()
{
	ifstream file;
	string value;
	int price;

	file.open("goods.txt");

	while (!file.eof()) {
		file >> value;
		file >> price;
		add_element(value, price);
		value = "";
		price = -1;
	}

	file.close();
}

void Table::add_element(string value, int price)
{
	Node *node = set, *parent = NULL;

	while (node != NULL) {
		parent = node;
		node = node->next;
	}

	node = create_node(node, parent);
	if (node == NULL) {
		return;
	}
	node->value = value;
	node->price = price;

	if (set == NULL) {
		set = node;
	}
}

Set::Node* Table::create_node(Node *node, Node *parent)
{
	node = new Node;
	if (node == NULL) {
		return node;
	}
	node->parent = parent;
	if (parent != NULL) {
		parent->next = node;
	}
	node->next = NULL;
	return node;
}

void Table::print_set()
{
	Node *node = set;
	cout << "Name\t" << "Price\t" << endl;
	while (node != NULL) {
		cout << node->value << "\t";
		cout << node->price << endl;
		node = node->next;
	}
}

void Table::search_product(string value)
{
	Node *node = lookup_element(value);

	if (node == NULL) {
		cout << "Error, product not found" << endl;
	} else {
		cout << "Found product:" << endl;
		cout << "Name\t" << "Price\t" << endl;
		cout << node->value << "\t" << node->price << endl;
	}
}

Set::Node* Table::lookup_element(string value)
{
	if (set == NULL) {
		input_table();
	}

	Node *node = set;
	while (node != NULL && node->value != value) {
		node = node->next;
	}

	return node;
}

void Table::delete_element(string value)
{
	Node *node = lookup_element(value);

	if (node == NULL) {
		cout << "Error, product for purchase not found" << endl;
	} else {
		if (node->next != NULL)
			node->next->parent = node->parent;
		if (node->parent != NULL) {
			node->parent->next = node->next;
		} else {
			set = node->next;
		}
		delete node;
	}
}

void Table::save_table()
{
	ofstream file;
	file.open("goods.txt");

	Node *node = set;
	while (node != NULL) {
		file << node->value << "\t";
		file << node->price;
		if (node->next != NULL)
			file << endl;
		node = node->next;
	}
	file.close();
}

#endif
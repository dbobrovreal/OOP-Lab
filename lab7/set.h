#ifndef SET_H
#define SET_H

#include <iostream>

using namespace std;

class Set
{
protected:
	struct Node
	{
		string value;
		int price;
		Node *next;
		Node *parent;
	};
	Node *set = NULL;
public:
	virtual Node* create_node(Node*, Node*) = 0;
	virtual void add_element(string, int) = 0;
	virtual void delete_element(string) = 0;
	virtual Node* lookup_element(string) = 0;
	virtual void print_set() = 0;
};

#endif
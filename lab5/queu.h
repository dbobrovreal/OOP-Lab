#ifndef QUEU_H
#define QUEU_H

#include "set.h"

class Queu: public Set
{
	Node *root = NULL;
public:
	Node *create_node (Node *node, Node *parent, int value)
	{
		node = new Node;
		if (node == NULL) {
			return NULL;
		}
		node->value = value;
		node->next = NULL;
		node->parent = parent;

		return node;
	}
	void add_element (int value)
	{
		Node *node = root, *parent = NULL;

		while (node != NULL) {
			parent = node;
			node = node->next;
		}

		node = create_node(node, parent, value);

		if (root == NULL) {
			root = node;
		} else {
			parent->next = node;
		}
	}
	void delete_element ()
	{
		Node *node = root;
		if (line() <= 0) {
			cout << "Error: not elem for delete" << endl;
			return;
		}
		if (node->next != NULL) {
			node->next->parent = NULL;
			root = node->next;
			delete node;
		} else {
			delete root;
			root = NULL;
		}
	}
	int line ()
	{
		Node *node = root;
		int i = 0;
		while (node != NULL) {
			node = node->next;
			i++;
		}
		return i;
	}
	void print ()
	{
		Node *node = root;
		cout << "Queu:\t";
		if (line() <= 0) {
			cout << "void" << endl;
			return;
		}
		while (node != NULL) {
			cout << node->value << "\t";
			node = node->next;
		}
		cout << endl;
	}
	~Queu ()
	{
		Node *node = root;
		while (root != NULL) {
			node = root->next;
			delete root;
			root = node;
		}
		delete node;
	}
};

#endif
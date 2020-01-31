#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct List {
	int value;
	List *next;
	List *parent;
};

List *create_node(List *node, List *parent, List *next, int value)
{
	node = new List;
	if (node == NULL) {
		return NULL;
	}
	node->value = value;
	node->next = next;
	node->parent = parent;
	return node;
}

void print_list (List *list)
{
	List *node = list;
	cout << "List:\t";
	while (node != NULL) {
		cout << node->value << "\t";
		node = node->next;
	}
	cout << endl;
}

int number_elem (List *list)
{
	List *node = list;
	int i = 0;
	while (node != NULL) {
		node = node->next;
		i++;
	}
	return i;
}

List *list_lookup(List *list, int i)
{
	List *node = list;
	i--;
	if (i < 0 && i + 1 > number_elem(list)) {
		cout << "Error 404" << endl;
		return NULL;
	}
	while (node != NULL && i != 0) {
		i--;
		node = node->next;
	}
	return node;
}

List *free_elem (List *list, int i)
{
	List *node = NULL, *node_parent = NULL, *node_next = NULL;
	List *arr = new List [2];

	node = list_lookup(list, i);
	if (node == NULL) {
		arr[0] = *list;
		arr[1] = *node;
		return arr;
	}
	cout << node->value << endl;

	arr[0] = *list;
	arr[1] = *node;

	node_parent = node->parent;
	node_next = node->next;

	if (node_parent != NULL) {
		node_parent->next = node_next;
	} else {
		list = node_next;
		arr[0] = *list;
	}

	if (node_next != NULL) {
		node_next->parent = node_parent;
	}

	return arr;
}

List *add_list(List *list, int value, int i)
{
	List *node = list, *parent = NULL, *next = NULL, *node_new = NULL;

	if (i < 1 || i > number_elem(list) + 1) {
		//cout << i << endl;
		//cout << number_elem(list) << endl;
		return list;
	}

	while (node != NULL && i != 1) {
		parent = node;
		node = node->next;
		i--;
	}

	if (node != NULL && node->parent != NULL && node->next != NULL) {
		node_new = create_node(node_new, parent, node, value);
		parent->next = node_new;
	} else if (node != NULL && node->next != NULL && node->parent == NULL) {
		node_new = create_node(node_new, parent, list, value);
		list->parent = node; 
		list = node_new;
	} else if (node != NULL && node->next == NULL && node->parent != NULL) {
		node_new = create_node(node_new, parent, node, value);
		parent->next = node_new;
	} else if (node == NULL) {
		node = create_node(node, parent, next, value);
		if (list == NULL) {
			list = node;
		} else if (parent != NULL) {
			parent->next = node;
		}
	}

	return list;
}

List *list_delete_elem (List *list, int i)
{
	List *node = list, *parent = NULL, *node_next = NULL;

	if (i < 0 || i > number_elem(list)) {
		cout <<"Нет элемента под номером " << i << endl;
		return list;
	}

	while (node != NULL && i != 1) {
		parent = node;
		node = node->next;
		i--;
	}

	node_next = node->next;
	if (node->next != NULL) {
		node_next->parent = parent;
	}
	if (parent != NULL) {
		parent->next = node_next;
	}

	if (list == node) {
		list = node_next;
	}

	delete node;

	return list;
}

List *list_swap_elem (List *list, int i, int new_i)
{
	List *node = list, *parent = NULL, *node_new = NULL, *parent_new = NULL;

	if (i <= 0 || i > number_elem(list)) {
		cout << "Нет элемента под номером " << i << endl;
		return list;
	}

	if (new_i <= 0 || new_i > number_elem(list)) {
		cout << "Нет элемента под номером " << new_i << endl;
		return list;
	}

	if (i - new_i == 0) {
		cout << "Элемент ужу стоит на этом месте" << endl;
		return list;
	}

	while (node != NULL && i != 1) {
		parent = node;
		node = node->next;
		i--;
	}

	if (parent != NULL) {
		parent->next = node->next;
	} else {
		list = node->next;
	}

	if (node->next != NULL) {
		node->next->parent = parent;
	}

	for (node_new = list; node_new != NULL && new_i != 1; new_i--){
		parent_new = node_new;
		node_new = node_new->next;
	}

	if (parent_new != NULL) {
		parent_new->next = node;
	} else {
		list = node;
	}

	node->next = node_new;
	node->parent = parent_new;

	if (node_new != NULL) {
		node_new->parent = node;
	}

	return list;
}

int index_elem (List *list, List *node) {
	int i = 0;
	for (List *node_new = list; node_new != NULL;) {
		if (node_new == node) {
			node_new = node_new->next;
			continue;
		} else if (node_new->value == node->value) {
			i++;
			return i;
		}
	}
	return i;
}

List *delete_all_elem (List *list)
{
	// int check = number_elem(list), i;

	for (List *node = list; node != NULL;)
	{
		for (List *node_new = list; node_new != NULL;) {
			if (node == node_new) {
				cout << "!=" << endl;
			} else if (node->value == node_new->value) {
				cout << "==" << endl;
				// i = index_elem(list, node_new);
			}
			node_new = node_new->next;
		}
		node = node->next;
	}

	return list;
}

int main()
{
	srand(time(0));

	List *list = NULL;//, *node;

	int size_mass = 8;
	int *mass = new int [size_mass];

	cout << "Ind: \t";
	for (int i = 1; i <= size_mass; i++) {
		cout << i << "\t";
	}
	cout << endl << endl;

	cout << "Arr:\t";
	for (int i = 0; i < size_mass; i++) {
		mass[i] = rand() % 10 + 1;
		cout << mass[i] << "\t";
		list = add_list(list, mass[i] * mass[i], i + 1);
	}
	cout << endl;

	print_list(list);
	cout << "Кол-во элементов в списке: " << number_elem(list) << endl << endl;

	list = add_list(list, 11, 9);
	print_list(list);
	cout << "Кол-во элементов в списке: " << number_elem(list) << endl << endl;

	list = list_delete_elem(list, 9);
	print_list(list);
	cout << "Кол-во элементов в списке: " << number_elem(list) << endl << endl;

	list = list_swap_elem(list, 8, 1);
	print_list(list);
	cout << "Кол-во элементов в списке: " << number_elem(list) << endl << endl;

	list = delete_all_elem(list);
	print_list(list);
	cout << "Кол-во элементов в списке: " << number_elem(list) << endl << endl;

	return 0;
}
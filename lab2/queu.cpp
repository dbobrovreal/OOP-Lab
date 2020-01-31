#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Queu {
	int value;
	Queu *next;
	Queu *parent;
};

Queu *create_node(Queu *node, Queu *parent, int value) {
	node = new Queu;
	if (node == NULL) {
		return NULL;
	}
	node->value = value;
	node->next = NULL;
	node->parent = parent;
	return node;
}

int queu_line (Queu *queu)
{
	Queu *node = queu;
	int i = 0;
	while (node != NULL) {
		node = node->next;
		i++;
	}
	return i;
}

Queu *add_Queu(Queu *queu, int value) {
	Queu *node = queu, *parent = NULL;

	if (queu_line(queu) >= 10) {
		cout << "\n" << "Error: Max line" << endl;
		return queu;
	}

	while (node != NULL) {
		parent = node;
		node = node->next;
	}

	node = new Queu;
	if (node == NULL) {
		return NULL;
	}

	node = create_node(node, parent, value);

	if (queu == NULL) {
		queu = node;
	} else {
		parent->next = node;
	}

	return queu;
}

Queu *queu_delete_elem (Queu *queu)
{
	Queu *node = queu;
	if (queu_line(queu) <= 0) {
		cout << "Error: not elem for delete" << endl;
		return queu;
	}

	node->next->parent = NULL;

	delete node;

	return queu->next;
}

void print_Queu (Queu *queu) {
	Queu *node = queu;
	cout << "Queu:\t";
	while (node != NULL) {
		cout << node->value << "\t";
		node = node->next;
	}
	cout << endl;
}

int main()
{
	srand(time(0));

	Queu *queu = NULL;

	int size_mass = 10;
	int *mass = new int [size_mass];

	cout << "Arr:\t";
	for (int i = 0; i < size_mass; i++) {
		mass[i] = rand() % 10 + 1;
		cout << mass[i] << "\t";
		queu = add_Queu(queu, mass[i]);
	}
	cout << endl;

	print_Queu(queu);

	queu = queu_delete_elem(queu);
	print_Queu(queu);

	queu = queu_delete_elem(queu);
	print_Queu(queu);

	queu = add_Queu(queu, 11);
	print_Queu(queu);

	return 0;
}
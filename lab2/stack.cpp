#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Stack {
	int value;
	Stack *next;
	Stack *parent;
};

Stack *create_node(Stack *node, Stack *parent, int value)
{
	node = new Stack;
	if (node == NULL) {
		return NULL;
	}
	node->value = value;
	node->next = NULL;
	node->parent = parent;

	return node;
}

int stack_line (Stack *stack)
{
	Stack *node = stack;
	int i = 0;
	while (node != NULL) {
		node = node->next;
		i++;
	}
	return i;
}

Stack *add_stack(Stack *stack, int value)
{
	Stack *node = stack, *parent = NULL;

	if (stack_line(stack) >= 10) {
		cout << "\n" << "Error: Max line" << endl;
		return stack;
	}

	while (node != NULL) {
		parent = node;
		node = node->next;
	}

	node = new Stack;
	if (node == NULL) {
		return NULL;
	}

	node = create_node(node, parent, value);

	if (stack == NULL) {
		stack = node;
	} else {
		parent->next = node;
	}

	return stack;
}

Stack *stack_delete_elem (Stack *stack)
{
	Stack *node = stack;
	if (stack_line(stack) <= 0) {
		cout << "Error: not elem for delete" << endl;
		return stack;
	}
	while (node->next != NULL) {
		node = node->next;
	}
	node->parent->next = NULL;

	delete node;

	return stack;
}

void print_stack (Stack *stack)
{
	Stack *node = stack;
	cout << "Stack:\t";
	while (node != NULL) {
		cout << node->value << "\t";
		node = node->next;
	}
	cout << endl;
}

int main()
{
	srand(time(0));

	Stack *stack = NULL;

	int size_mass = 10;
	int *mass = new int [size_mass];

	cout << "Arr:\t";
	for (int i = 0; i < size_mass; i++) {
		mass[i] = rand() % 10 + 1;
		cout << mass[i] << "\t";
		stack = add_stack(stack, mass[i]);
	}
	cout << endl;

	print_stack(stack);

	stack = stack_delete_elem(stack);
	print_stack(stack);

	stack = stack_delete_elem(stack);
	print_stack(stack);

	stack = stack_delete_elem(stack);
	print_stack(stack);

	stack = add_stack(stack, 11);
	print_stack(stack);

	cout << "Line: " << stack_line(stack) << endl;

	return 0;
}
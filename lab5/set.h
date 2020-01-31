#ifndef SET_H
#define SET_H

using namespace std;

class Set
{
protected:
	struct Node
	{
		int value;
		Node *next;
		Node *parent;
	};
public:
	virtual void add_element (int) = 0;
	virtual void delete_element () = 0;
	virtual int line () = 0;
	virtual void print () = 0;
};

#endif
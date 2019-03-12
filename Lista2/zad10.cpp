#include <iostream>

using namespace std;

struct node {
	int x;
	node* left;
	node* right;

	node (int x0, node* l=NULL, node* r=NULL)
		:x(x0), left(l), right(r)
	{}
};

void insert(node *&t, int x) {
	node **t1 = &t;
	while (*t1)
		if (x < (*t1) -> x)
			t1 = &((*t1) -> left);
		else
			t1 = &((*t1) -> right);
	*t1 = new node(x);
}

node* find(node* t, int x) {
	while (t && t -> x != x) {
		if (x < t -> x) 
			t = t -> left;
		else
			t = t -> right;
	}
	return t;
}

void remove(node *&t, int x) {
	node **t1 = &t;
	while (*t1 && (*t1) -> x != x) {
		if (x < (*t1) -> x)
			t1 = &((*t1) -> left);
		else
			t1 = &((*t1) -> right);
	}
	if (*t1) {
		if ((*t1) -> right && (*t1) -> left) {
			node **t2 = &((*t1) -> right);
			while ((*t2) -> left)
				t2 = &((*t2) -> left);
			(*t1) -> x = (*t2) -> x;
			t1 = t2;
		}
		if ((*t1) -> left == NULL) {
			node *d = (*t1) -> right;
			delete *t1;
			(*t1) = d;
		} else {
			node *d = (*t1) -> left;
			delete *t1;
			(*t1) = d;
		}
	}
}

int main() {


	return 0;
}
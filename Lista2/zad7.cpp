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

int counter = 0;

void insert(node *&t, int x) {
	node **t1 = &t;
	while (*t1)
		if (x < (*t1) -> x) {
			t1 = &((*t1) -> left);
			counter++;
		}
		else {
			t1 = &((*t1) -> right);
			counter++;
		}
	*t1 = new node(x);
}

void inorder(node *t) {
	if (t) {
		inorder (t -> left);
		std::cout << t -> x << " ";
		inorder (t -> right);
	}
}

int H(node* t) {
	if (!t) return 0;
	int hL = H(t -> left);
	int hR = H(t -> right);
	if (hR > hL)
		return 1 + hR;
	else
		return 1 + hL;
}

void display(node *t, char z1 = ' ', char z2 = ' ') {
	if (t) {
		std::cout << z1;
		display(t -> left, '(', ')');
		std::cout << t -> x;
		display(t -> right, '[', ']');
		std::cout <<  z2;
	}
}

int main() {
	node* T = NULL;

	insert(T, 1);
	insert(T, 9);
	insert(T, 3);
	insert(T, 11);
	insert(T, 5);

	//inorder(T);
	display(T);
	std::cout << "Wysokość: ";
	std::cout << H(T) << std::endl;
	std::cout << "Licznik: " << counter << std::endl;

	return 0;
}
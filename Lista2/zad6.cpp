#include <iostream>

using namespace std;

struct lnode {
	int key;
	lnode *next;
	lnode(int key0, lnode* nxt=NULL)
		:key(key0), next(nxt)
	{}
};

void insert(lnode*& t, int key) {
	lnode **t1 = &t;
	while (*t1)
		t1=&((*t1)->next);
	*t1 = new lnode(key);
}

void display(lnode *t, char z1 = ' ', char z2 = ' ') {
	if (t) {
		std::cout << z1;
		display(t->next, '(',')');
		std::cout << t -> key;
		//display(t->next, '[', ']');
		std::cout << z2;
	}
}

int counter = 0;

lnode* merge(lnode* L1, lnode* L2) {
	lnode* resultL = NULL;
	if (L1 == NULL) {
		counter++;
		return (L2);
	} 
	if (L2 == NULL) {
		counter++;
		return (L1);
	}

	if (L1 -> key <= L2 -> key) {
		resultL = L1;
		resultL -> next = merge(L1 -> next, L2);
	} else {
		resultL = L2;
		resultL -> next = merge(L1, L2 -> next);
	}
	counter++;
	return (resultL);
}

int main() {
	lnode* L1 = NULL;

	insert(L1, 1);
	insert(L1, 2);
	insert(L1, 3);
	insert(L1, 4);
	insert(L1, 5);

	display(L1);

	lnode* L2 = NULL;

	insert(L2, 6);
	insert(L2, 7);
	insert(L2, 8);
	insert(L2, 9);
	insert(L2, 10);

	display(L2);

	std::cout << "Merged: " << std::endl;

	lnode* L3 = merge(L1, L2);

	display(L3);

	std::cout << "Counter: " << counter << std::endl;

	return 0;
}
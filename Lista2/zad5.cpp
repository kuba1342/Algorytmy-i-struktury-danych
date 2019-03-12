#include <iostream>

using namespace std;

// struct lnode {
// 	int x;
// 	lnode* left;
// 	lnode* right;
// 	lnode(int x0, lnode* l=NULL, lnode* r=NULL)
// 		:x(x0), left(l), right(r)
// 	{}
// };

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

void reverse(lnode*& L) {
	if (L) {
		//display(L->next);
		//std::cout << L -> key << std::endl;
		lnode* current = L;
		lnode* next = NULL;
		lnode* prev = NULL;

		while (current != NULL) {
			next = current -> next;
			current -> next = prev;
			prev = current;
			current = next;
		}
		L = prev;
	}
}

// void insert(lnode*& t, int x) {
// 	lnode **t1 = &t;
// 	while (*t1)
// 		if(x<(*t1)->x)
// 			t1=&((*t1)->left);
// 		else
// 			t1=&((*t1)->right);
// 	*t1 = new lnode(x);
// }

// void display(lnode *t, char z1 = ' ', char z2 = ' ') {
// 	if(t) {
// 		std::cout << z1;
// 		display(t->left, '(',')');
// 		std::cout << t->x;
// 		display(t->right, '[',']');
// 		std::cout << z2;
// 	}
// }

int main() {
	lnode* t = NULL;

	insert(t, 3);
	insert(t, 4);
	insert(t, 1);
	insert(t, 5);
	insert(t, 2);

	display(t);
	reverse(t);
	std::cout << "_____________________" << std::endl;
	display(t);

	return 0;
}
#include <iostream>

using namespace std;

void reverse(int *tab, int begin, int end) {
	int tmp;

	while (begin < end) {
		tmp = tab[begin];
		tab[begin] = tab[end];
		tab[end] = tmp;
		begin++;
		end--;
	}
}

void move(int *tab, int n, int k) {
	reverse(tab, 0, n-1);
	reverse(tab, 0, k-1);
	reverse(tab, k, n-1);
}
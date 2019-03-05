#include <iostream>

using namespace std;

void findX(int tab[], int x) {
	int l = 1;
	int p = sizeof(tab)/sizeof(*tab);

	for (int i = 0; i < p; i++) {
		if (l > p) {
			std::cout << "Nie ma takiego elementu." << std::endl;
			break;
		} else {
			int s = (l + p) / 2;
			if (tab[s] == x) {
				std::cout << "Znaleziono x w miejscu: " << s << std::endl;
				break;
			} else {
				if (tab[s] < x) {
					l = s + 1;
				} else {
					p = s - 1;
				}
			}
		}
	}
}

int main() {
	int a[6] = {1, 2, 4, 6, 7};
	findX(a, 2);
	return 0;
}
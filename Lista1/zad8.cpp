#include <iostream>
#include <cmath>

using namespace std;

class ulamek {
private:
	int licznik;
	int mianownik;
public:
	 ulamek () {}

	ulamek (int a, int b) {
		licznik = a;
		mianownik = b;
	}

	int NWD(unsigned int a, unsigned int b) {
		if (a == 0 || b == 0) {
			return 1;
		}
		while (a!=b) {
			if (a > b) {
				a -= b;
			} else {
				b -= a;
			}	
		}
		return a;
	}

	ulamek operator+ (ulamek b) {
		ulamek c;
		int wspM = mianownik * b.getMianownik();
		int cLicznik = (licznik * b.getMianownik()) + (b.getLicznik() * mianownik);
		int cNWD = NWD(cLicznik, wspM);
		c.setLicznik(cLicznik / cNWD);
		c.setMianownik(wspM / cNWD);
		return c;
	}

	ulamek operator- (ulamek b) {
		ulamek c;
		int wspM = mianownik * b.getMianownik();
		int cLicznik = licznik * b.getMianownik() - b.getLicznik() * mianownik;
		int cNWD = NWD(abs(cLicznik), abs(wspM));
		std::cout << cNWD << std::endl;
		c.setLicznik(cLicznik / cNWD);
		c.setMianownik(wspM / cNWD);
		return c;
	}

	ulamek operator* (ulamek b) {
		ulamek c(0, 0);
		int cLicznik = licznik * b.getLicznik();
		int cMianownik = mianownik * b.getMianownik();
		int cNWD = NWD(cLicznik, cMianownik);
		c.setLicznik(cLicznik / cNWD);
		c.setMianownik(cMianownik / cNWD);
		return c;
	}

	ulamek operator/ (ulamek b) {
		ulamek c(0, 0);
		int cLicznik = licznik * b.getMianownik();
		int cMianownik = mianownik * b.getLicznik();
		int cNWD = NWD(cLicznik, cMianownik);
		c.setLicznik(cLicznik / cNWD);
		c.setMianownik(cMianownik / cNWD);
		return c;
	}

	int getLicznik() {
		return licznik;
	}

	int getMianownik() {
		return mianownik;
	}

	void setLicznik(int _licznik) {
		licznik = _licznik;
	}

	void setMianownik(int _mianownik) {
		mianownik = _mianownik;
	}
};

	std::ostream& operator<< (std::ostream& os, ulamek& a) {
		os << a.getLicznik() << "/" << a.getMianownik();
		return os;
	}

	std::istream& operator>> (std::istream& is, ulamek& a) {
		int licznik;
		int mianownik;
		char c;
		is >> licznik;
		is >> c;
		if (c == '/') {
			is >> mianownik;
		} else {
			is.putback(c);
			mianownik = 1;
		}
		a = ulamek(licznik, mianownik);
		return is;
	}

int main() {
	// ulamek a;
	// std::cin >> a;
	// std::cout << a << std::endl;
	// ulamek b;
	// std::cin >> b;
	// std::cout << b;

	ulamek a;
	ulamek b;
	std::cin >> a;
	std::cin >> b;
	ulamek c = a + b;
	ulamek d = a - b;
	ulamek e = a * b;
	ulamek f = a / b;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;
	std::cout << f << std::endl;



	return 0;
}
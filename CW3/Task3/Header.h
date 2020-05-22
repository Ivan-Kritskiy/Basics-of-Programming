#include <iostream>
using namespace std;
struct triangle {
	int bokova;
	int bokova2;
	int osnova;
	triangle(int b, int b2, int o) {
		bokova = b;
		bokova2 = b;
		osnova = o;
	}
	void method() {
		cout << sqrt((bokova * bokova2) - (osnova * osnova) / 4);
	}
};

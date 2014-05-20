#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	const int bound = 1001;
	int a = 1, b = 3, c = 5, d = 7, k = 2;
	long sum = 1;
	for (int i = 0; i < bound; i++) {
		sum += (k + a) + (k + b) + (k + c) + (k + d);
		a += k;
		b += k;
		c += k;
		d += k;
		k += 8

	}
	int k = 2, a = 1, sum = 1;
	for (int i = 0; i < (bound / 2) + 1; i++) {
		sum += k + a; 
		a += k;
		k += 8;
	}
	cout << sum << endl;
}

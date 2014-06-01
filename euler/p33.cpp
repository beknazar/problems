#include <vector>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <stdio.h>
#include <sstream>
using namespace std;
const double EPSILON = 0.00001;
bool check (int a, int b) {
	int m = a, n = b;
	for (int i = 0; i < 2; i++) {
		int k = a % 10;
		for (int j = 0; j < 2; j++) {
			int l = b % 10;
			b /= 10;
			if (k == l) {
				a = (i == 0 ? m / 10 : m % 10);
				b = (j == 0 ? n / 10 : n % 10);
				return abs ((1.0*a/b) - (1.0*m/n)) < EPSILON;
			}
		}
		a /= 10;
	}
}

int main() {
	// int a = 4, b = 8, m = 49, n = 98;
	for (int i = 11; i < 100; i++) {
		for (int j = i - 1; j > 10; j--) {
			if (i % 10 != 0 && j % 10 != 0 && check(j, i)) {
				cout << i << " : " << j << endl;
			}
		}
	}
	// cout << check(16, 64) << endl;
}
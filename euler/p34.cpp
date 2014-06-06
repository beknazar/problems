#include <vector>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <stdio.h>
#include <sstream>
using namespace std;

int fact (int n) {
	if (n < 2) return 1;
	return n * fact(n - 1);
}

bool check (int n, int * fac) {
	int sum = 0, original_n = n; 
	while (n) {
		sum += fac[n % 10];
		n /= 10;
		if (sum > original_n) return 0;
	}
	return sum == original_n ? 1 : 0;
}

int main() {
	const int size = 10, limit = 9999999;
	int* fac = new int[size];
	for (int i = 0; i < size; i++) fac[i] = fact(i);

	cout << check (145, fac) << endl;
	for (int i = 3; i < limit; i++) {
		if (check (i, fac)) {
			cout << i << endl;
		}
	}
}
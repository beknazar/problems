#include <vector>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <stdio.h>
#include <sstream>
#include <limits.h>
using namespace std;

bool isPrime (int n) {
	if (n == 2) return 1;
	if (n % 2 ==0) return 0;
	for (int i = 3; i*i <= n; i+=2) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int main() {

	bool notFound = 1;
	int n = 1, p;
	while (notFound) {
		n++;
		int k = 1;
		do {
			p = 2*(n - k*k) + 1;
			if (p < 2 && !isPrime(2*n + 1)) {
				notFound = 0;
				break;
			}
			k++;
		} while (!isPrime(p));
	}

	cout << "The smallest odd composite that cannot be written as the sum of a prime and twice a square is: " << 2*n + 1 << endl;
}
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

bool isPrime(int n) {
	if (n == 2) return 1;
	if (n % 2 == 0) return 0;
	for (int i = 3; i*i <= n; i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}

bool isPandigital (int n) {
	int digits = 0, count = 0, tmp;

	for (; n > 0; n /= 10, ++count) {
		if ((tmp = digits) == (digits |= 1 << (n - ((n / 10) * 10) - 1)))
			return 0;
	}
	return digits == (1 << count) - 1;
}

/*
Note: Nine numbers cannot be done (1+2+3+4+5+6+7+8+9=45 => always dividable by 3)
Note: Eight numbers cannot be done (1+2+3+4+5+6+7+8=36 => always dividable by 3)
*/

int main() {
	const int limit = 7654321;
	
	for (int i = limit; i >= 2143; i -= 2) {
		if (isPandigital(i)) {
			if (isPrime(i)) {
				cout << "Largest n-digit pandigital number: " << i << endl;
				return 0;
			}
		}
	}
	// cout << isPandigital(limit) << endl;
	// cout << isPrime(987654321) << endl;
	// cout << "Maximised P is: " << maxP << " with # of solutions: " << max << endl;
}
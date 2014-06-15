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
	if (n % 2 == 0) return 0;
	for (int i = 3; i*i <= n; i+=2)
		if (n % i == 0) return 0;
	return 1;
}

int check (int n, int k) {
	int onbir, len = log10(n), count = 0;
	if (k == 1) onbir = 1;
	else k == 2 ? onbir = 11 : onbir = 11 + pow(10, k - 1);
	for (int i = 1; i < 10; i++) {
		k = (i * onbir) * pow(10, len + 1) + n;
		if (isPrime(k)) {
			count++;
			// cout << k << endl;
		}
	}
	return count;
}

int main() {
	const int limit = 1000;
	int k = 3;
	int primes[limit]; primes[0] = 2;
	for (int i = 0; i < limit; k+=2) {
		if (isPrime(k)) primes[++i] = k;
	}
	int count;
	bool notFound = 1;
	for (int i = 0; notFound && i < limit; i++) {
		for (int k = 1; k < 5; k++) {
			count = check (primes[i], k);
			cout << count << endl;
			if (count == 5) {
				notFound = 0;
				cout << "The smallest such prime is: " << primes[i] << endl;
				break;
			}
		}
	}
	// cout << check (3, 2) << endl;
}
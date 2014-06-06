#include <vector>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <stdio.h>
#include <sstream>
using namespace std;

bool isPrime (int n) {
	if (n % 2 == 0) return 0;
	if (n < 9) return 1;
	for (int i = 3; i*i <= n; i+=2) {
		if (n % i == 0) return 0;
	}
	return 1; 
}

bool check (int n) {
	if (!isPrime(n)) return 0;
	int len = log10(n) + 1;
	for (int i = 0; i < len - 1; i++) {
		int k = (n % (int)pow(10, len - i - 1)) * pow(10, i + 1) + n / pow(10, len - i - 1);
		if (!isPrime(k)) return 0;
	}
	return 1;
}



int main() {
	const int limit = 1000000;
	int count;

	for (int t = 0; t < 100; t++) {
		count = 0;
		for (int i = 3; i < limit; i += 2) {
			if ((i / 10) % 2 && (i / 100) % 2) {
				if (check (i)) {
					count++; // counts circular primes between (100, 10^6)
				}
			}
		}
	}

	cout << "Number of circular primes below 1 million: " << count + 13 << endl;
	return 0;
}
#include <vector>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <stdio.h>
#include <sstream>
#include <limits.h>
#include <algorithm>
using namespace std;
const int size = 1061;
int primes[size];


bool isPrime(int n) {
	if (n == 2) return 1;
	if (n % 2 == 0) return 0;
	for (int i = 3; i*i <= n; i+=2)
		if (n % i == 0) return 0;
	return 1;
}

bool isPerm (int a, int b) {
	ostringstream ss, tt;
	ss << a;
	tt << b;
	string s = ss.str();
	string t = tt.str();
	sort (s.begin(), s.end());
	sort (t.begin(), t.end()); 
	return s == t;
}

int main() {
	int count = 0;
	for (int i = 1001; i < 10000; i+=2) {
		if (isPrime(i)) primes[count++] = i;
	}
	bool notFound = 1;
	for (int i = 0; notFound && i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (isPrime(2 * primes[j] - primes[i])) {
				// cout << primes[i] << endl;
				if (primes[i] != 1487 && isPerm (primes[i], primes[j]) && isPerm (primes[j], 2 * primes[j] - primes[i])) {
					cout << "FOUND! " << primes[i] << primes[j] << 2*primes[j] - primes[i] << endl;
					notFound = 0;
					break;
				}
			}
		}
	}
	// if (isPerm (1487, 4817) && isPerm(4817, 8147))
		// cout << "yes" << endl;
	// cout << "Last 10 digits: " << count << endl;
}
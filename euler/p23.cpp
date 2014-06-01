#include <vector>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <stdio.h>
#include <sstream>
using namespace std;
const int size = 28123;

bool isPrime(int n) {
	if (n == 2) return 1;
	if (n%2 == 0) return 0;
	for (int i = 3; i*i <= n; i+=2) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int d(int n) {
	// if (n < size && arr[n]) return arr[n]; // memoization
	int sum = 1, c = 0, last, k = n;
    for (int i = 2; i <= n | c;) {
		if (n % i == 0) {
			last = i;
			n /= i;
			c++;
		}
		else {
			if (c) {
				int s = 1;
				for (int j = 1; j <= c; j++) {
					s += pow(last, j);
				}
				sum *= s;
			}
			c = 0;
			i++;
		}
	}
	if (n > 1) {
		sum *= (1 + n);
	}
	// arr[k] = sum - k;
	return sum - k;
}
 
int main() {
	int s = 6965, ds[s], count = 0;
	for (int i = 1; i <= size; i++) {
		if (d(i) > i) {
			ds[count] = i;
			count++;
		}
	}
	int ks[size*2];
	for (int i = 0; i < size*2; i++) ks[i] = 0;
	for (int i = 0; i < s; i++) {
		for (int j = i; j < s; j++) ks[ds[i] + ds[j]] = 1;
	}

	long sum = 0;
	for (int i = 0; i <= size; i++) {
		if (ks[i] == 0) sum += i;
	}
	cout << sum << endl;
}
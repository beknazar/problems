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

int nextPrime (int n) {
	n % 2 == 0 ? n+=1 : n+=2; 
	while (!isPrime(n)) n += 2;
	return n;
}

int main() {
	const int limit = 1000000;
	int sum = 0, count, max = 0, maxSum;
	int k = 2, c;
	for (c = 2; k < limit; c++) {
		k = nextPrime(k);
	}
	k = 2;
	int* primes = new int[c];
	for (int i = 0; i < c; i++) {
		primes[i] = k;
		k = nextPrime(k);
	}
	for (int i = 0; i < c; i++) {
		sum = primes[i];
		count = 0;
		for (int j = i+1; sum < limit; j++) {
			sum += primes[j];
			count++;
			if (count > max && isPrime(sum)) {
				max = count;
				maxSum = sum;
			}
		}
	}
	cout << "Sum of such numbers is: " << maxSum << endl;
}
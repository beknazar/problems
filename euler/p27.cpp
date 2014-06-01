#include <iostream>
#include <stdio.h>
using namespace std;

bool isPrime(int n) {
	if (n == 2) return 1;
	if (n % 2 == 0) return 0;
	for (int i = 3; i * i <= n; i++) if (n % i == 0) return 0;
	return 1;
}

int main() {
	const int bound = 1000;
	int b = 43, maxProduct, max = 0, maxA, maxB;
	for (; b < bound; b+=2) {
		int a = 2 - b;
		for (; a < bound; a+=2) {
			int n = 0, k = 1 + a + b;
			while (k > 1 && isPrime(k)) {
				k = n*n+a*n+b;
				n++;
			}
			if (n > max) { 
				max = n;
				maxProduct = a*b;
				maxA = a;
				maxB = b;
			}
		} 
	}
	printf("maxA: %d; maxB: %d\n", maxA, maxB);
	cout << max << " Product a*b: " << maxProduct << endl;
}

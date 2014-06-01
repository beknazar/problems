#include <iostream>

using namespace std;

bool isPrime(int n) {
	for (int i = 3; i*i <= n; i+=2) {
		if (n%i == 0) return 0;
	}
	return 1;
}

int main() {
	unsigned long long n = 600851475143;
	// int n = 13195;
	for (int i = 3; n > 1; i += 2) {
		if (isPrime(i) && n%i == 0) { 
			n /= i;
			cout << i << " ";
		}
	}
	// cout << sum << endl;
}
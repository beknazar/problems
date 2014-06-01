#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n) {
	for (int i = 3; i*i <= n; i+=2) {
		if (n%i == 0) return 0;
	}
	return 1;
}

int main() {
	unsigned long long sum = 2;
	int n = 2*pow(10,6);
	for (int i = 3; i < n; i += 2) {
		if (isPrime(i)) { 
			sum += i;
		}
	}
	cout << sum << endl;
}
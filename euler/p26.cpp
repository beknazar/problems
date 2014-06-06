#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int n) {
	if (n % 2 == 0) return 0;
	for (int i = 3; i*i <= n; i++) if(n % i == 0) return 0;
	return 1;
}

int main() {
	int n = 999;
	while(n > 2) {
		if (isPrime(n) == 1) cout << n << endl;
		n--;
	}
	// cout << isPrime(998) << endl;
}


#include <iostream>

using namespace std;

bool isPrime(int n) {
	for (int i = 3; i*i <= n; i+=2) {
		// if (n < 200) cout << n << " ";
		if (n%i == 0) return 0;
	}
	return 1;
}

int main() {
	// unsigned long long n = 600851475143;
	int n = 2520;
	bool flag;
	while (1) {
		flag = 1;
		for (int i = 19; i > 10; i--) {
			if (n % i != 0) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			cout << n << endl; 
			break;
		}
		n += 20;
	}
	// cout << n << endl;
}
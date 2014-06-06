#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int numOfDigits = 0, n = 2;
	double phi = (1 + sqrt(5)) / 2.0;
	for (; numOfDigits < 1000; n++) {
		numOfDigits = n*log10(phi) - 0.5 * log10(5.0);
	}
	cout << n << endl;
	double f = pow(phi, n) / sqrt(5);

	cout << f << endl;
	// cout << fib(n) << endl;
}


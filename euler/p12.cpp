#include <iostream>
#include <cmath>
using namespace std;

int numOfDivisors(int n) {
	int count = 0;

	for (int i = 1; i*i <= n; i++) {
		if (n % i == 0) count+=2;
	}
	return count;
}

int main() {
	int n = 0, i = 1;

	while (numOfDivisors(n) <= 500) {
		n += i;
		i++;
	}
	cout << n << endl;
}

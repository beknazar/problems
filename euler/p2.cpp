#include <iostream>

using namespace std;

unsigned long long fib(int n) {
	if(n == 0) return 0;
	if(n == 1) return 1;
	return fib(n-1) + fib(n-2);
}

int main() {
	unsigned long long sum = 0, n;
	int i = 3;
	do {
		n = fib(i);
		if (n % 2 == 0) sum += n;
		i++;
	} while(n < 4000000);
	cout << sum << endl;
}
#include <iostream>
#include <ctime>

using namespace std;

bool isPrime(int n) {
	// cout << n << " ";
	for (int i = 3; i*i <= n; i+=2) {
		if (n%i == 0) return 0;
	}
	return 1;
}

int main() {
	clock_t begin = clock();
	int count = 1, i = 3;
	for (; count < 10001; i += 2) {
		if (isPrime(i)) count++;
	}
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC*1.0;
	cout << i-2 << endl;
	cout << "time: " << elapsed_secs << " seconds" << endl;
}
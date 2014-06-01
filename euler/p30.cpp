#include <iostream>
#include <cmath>
#include <set>
using namespace std;

int sum(int n) {
	int k, s = 0;
	while (n) {
		k = n % 10;
		s += pow(k, 5);
		n /= 10;
	}
	return s;
}

int main() {
	const int limit = 1000000;
	int s = 0;
	for (int i = 2; i < limit; i++) {
		if(i == sum(i)) s += i;
	}
	cout << s << endl;
}
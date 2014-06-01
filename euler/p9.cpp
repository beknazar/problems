#include <iostream>

using namespace std;

int abs(int n) {
	if (n < 0) return n*(-1);
	return n;
}
int sum(int b) {
	int a, c, m, n, mn = b/2;
	for (int i = 1; i < mn/2; i++) {
		if (mn%i == 0) {
			n = mn/i;
			m = i;
			a = abs(m*m - n*n);
			c = m*m + n*n;
			if (a + b + c == 1000) return m;
		}
	}
	return 0;
}

int main() {
	int b = 100, m = 0;
	while (m == 0) {
		b += 2;
		m = sum(b);
	}
	int mn = b/2, n = mn/m;
	int a = abs(m*m - n*n), c = m*m + n*n;
	cout << "a: " << a << " b: " << b << " c: " << c << endl;
	cout << "product[abc]: " << a*b*c << endl;
	
}
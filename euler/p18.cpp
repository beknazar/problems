#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int max, n, size, last;
	cin >> size;
	unsigned long sum = 0;
	for (int i = 0; i < size; i++) {
		max = 0;
		for (int j = 0; j < i + 1; j++) {
			cin >> n;
			if (j == last || j == last + 1 && n > max) {
				max = n;
				last = j;
			}
		}
		cout << last << endl;
		sum += max;
	}
	cout << sum << endl;
}
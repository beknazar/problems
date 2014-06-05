#include <vector>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <stdio.h>
#include <sstream>
#include <limits.h>
using namespace std;

bool check (int c, int p) {
	int apb = p - c;
	for (int i = 1; i < apb/2; i++) {
		if (c*c == i*i + (apb - i) * (apb - i)) return 1;
	}
	return 0;
}

int main() {
	const int limit = 1000;
	int max = 0, maxP = 0;
	for (int p = 12; p < limit; p+=2) {
		int count = 0;
		for (int c = p / 2; c > p / 3; c--) {
			if (check (c, p)) count++;
		}
		if (count > max) {
			max = count;
			maxP = p;
		}
	}

	cout << "Maximised P is: " << maxP << " with # of solutions: " << max << endl;
}
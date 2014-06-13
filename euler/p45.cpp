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

bool isTri (int x) {
	double k = (sqrt(1+8.0*x) - 1.0) / 2;
	return k == (int)k;
}

bool isHex (int x) {
	double k = (sqrt(1+8.0*x) + 1) / 4;
	return k == (int)k;
}

bool isPen (int x) {
	double k = (sqrt(1 + 24.0*x) + 1)/6;
	return k == (int)k;
}


int main() {
	int res;
	for (int i = 40756; ; i++) {
		if (isPen(i) && isHex(i)) {
			res = i;
			break;
		}
	}
	cout << "Next triangle number that is also pentagonal and hexagonal is: " << res << endl;
}
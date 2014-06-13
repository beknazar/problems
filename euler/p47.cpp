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

int factor (int n) {
	int count = (n % 2 == 0);	
	while (n % 2 == 0)
		n /= 2;
	int last = 0;
	for (int i = 3; i * i <= n; ) {
		if (n % i == 0) {
			n /= i;
			if (last != i) count++;
			last = i;
		}
		else i += 2;
	} 
	if (n > 1 && last != n) count++;
	return count;
}

int main() {
	bool notFound = 1;
	int count = 0, i = 647;
	for (; count != 4; i++) {
		if (factor (i) == 4) count++;
		else count = 0;
	}
	cout << "First of these numbers: " << i - 4 << endl;
}
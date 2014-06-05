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

void init (bool * arr) {
	for (int i = 0; i < 10; i++) arr[i] = 0;
}

bool check (int n, bool * arr, int & count) {
	int k;
	while (n) {
		k = n % 10;
		if (k && !arr[k]) {
			arr[n % 10] = 1;
			count++;
		}
		else return 0;
		n /= 10;
	}
	return 1;
}

int main() {
	int k = 10, count;
	bool yes, arr[10];
	string s, max = "";

	for (int i = 9; i < 9999; i++) {
		init(arr);
		yes = 0;
		count = 0;
		s = "";
		for (int j = 1; !yes; j++) {
			if (check (i*j, arr, count)) {
				ostringstream ss;
				ss << i * j;
				// cout << "y: " << i*j << endl;
				s += ss.str();
			}
			else if (count == 9) {
				// cout << s << endl;
				if (s > max) max = s;
				// cout << "I: " << i << endl;
				yes = 1;
			}
			else break;
		}
		if ((int)log10(i + 1) > (int)log10(i)) {
			i = 9*k;
			k *= 10;
		}
	}

	cout << "Maximum is: " << max << endl;
}
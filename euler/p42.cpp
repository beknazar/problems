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

bool check (string s) {
	int sum = 0;
	for (int i = 0; i < s.length(); i++) {
		sum += s[i] - 64;
	}
	int d = sqrt(1 + 8*sum);
	if (d*d == 1+8*sum) return 1;
	return 0;

}

int main() {
	string s;
	int count = 0;
	while (getline(cin, s))
		if (check (s)) count++;
	cout << "# of triangle words is: " << count << endl;
}
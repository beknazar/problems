#include <vector>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <stdio.h>
#include <sstream>
using namespace std;


int main() {
	const int limit = 1000000;
	string s;
	for (int i = 1; i < limit / 1; i++) {
		ostringstream ss;
		ss << i;
		s += ss.str();
	}
	int res = 1;
	for (int i = 1; i <= limit; i*=10) {
		res *= (s[i - 1] - '0');
	}
	cout << "Result of the expression is: " << res << endl;
}
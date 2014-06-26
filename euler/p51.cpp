#include <vector>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <stdio.h>
#include <sstream>
#include <limits.h>
#include <algorithm>
using namespace std;

bool isPrime (int n) {
	if (n == 2) return 1;
	if (n % 2 == 0) return 0;
	for (int i = 3; i * i <= n; i+=2) 
		if (n % i == 0) return 0;
	return 1;
}

int num (const string & str, char c) {
	int count = 0, n;
	string number;
	for (int i = 0; i < 10; i++) {
		number = str;
		char b = i + '0';
		replace(number.begin(), number.end(), c, b);
		n = atoi(number.c_str());
		if (number.length() == ((int)log10(n)+1) && isPrime(n)) 
			count++;
	}
	return count;
}

bool check (int n, int k) {
	ostringstream ss;
	ss << n;
	string number = ss.str();
	int len = number.length();
	for (int i = 0; i < len - 1; i++) {
		if ((num(number, number[i])) == k) return 1;
	}
	return 0;
}

int main() {
	for (int i = 56993; ; i+=2) {
		if (check (i, 8)) { 
			cout << "First prime in the eight prime family is " << i << endl;
			break;
		}
	}
}
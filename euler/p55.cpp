#include <vector>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <stdio.h>
#include <sstream>
#include <limits.h>
#include <list>
using namespace std;

bool isPalindrome (const string& n) {
	int len = n.length();
	for (int i = 0; i < len/2; i++) {
		if (n[i] != n[len - 1 - i]) return 0;
	}
	return 1;
}

string addStrings (const string& a, const string& b) { // adding two string numbers of same len
	int len = a.length();
	string result = "";
	char add;
	int k, rem = 0;
	for (int i = len - 1; i >= 0; i--) {
		k = (a[i] - '0') + (b[i] - '0') + rem;
		rem = k / 10;
		add = k % 10 + '0';
		result = add + result;
	}
	add = rem + '0';
	if (rem > 0) result = add + result;
	return result;
}

string transform (const string& n) {
	int len = n.length();
	string rev = "";
	for (int i = len - 1; i >= 0; i--) {
		rev += n[i];
	}
	return addStrings(rev, n);
}

bool check (const string& number) {
	int count;
	string n = number;
	do {
		n = transform(n);
		count++;
		if (count == 50) return 1;
	} while (!isPalindrome(n));
	return 0;
}

int main() {
	const int limit = 10000;
	int count = 0;
	for (int i = 10; i < limit; i++) {
		string iString = "";
		int n = i;
		while (n) {
			char c = n%10 + '0';
			n/=10;
			iString = c + iString; 
		}
		if (check(iString)) count++;
	}
	printf("%d\n", count);
}
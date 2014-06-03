#include <vector>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <stdio.h>
#include <sstream>
using namespace std;

template <typename T>
string numToString (T number) {
	ostringstream ss;
	ss << number;
	return ss.str();
}

string decToBin (int number) {
	if (number == 0) return "0";
	if (number == 1) return "1";

	if (number % 2 == 0) 
		return decToBin (number / 2) + "0";
	else
		return decToBin (number / 2) + "1";
}

bool isPalindrome (string number) {
	int len = number.length();
	for (int i = 0; i < len/2; i++)
		if (number[i] != number[len - i - 1]) return 0;
	return 1;
}

int f (int number) {
	while (number >= 10)
		number /= 10;
	return number;
}

int main() {
	const int limit = 1000000;
	long sum = 0;
	for (int i = 1; i < limit; i++) {
		if (i % 10 && f(i) == i % 10) {
			if (isPalindrome(numToString(i)) && isPalindrome (decToBin(i)))
				sum += i;
		}
	}
	cout << "Sum of palindromic numbers below million: " << sum << endl;
}
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
const long digits = pow(10, 10);

long mult (long a, int b) {
	return ((a%digits)*(b%digits))%digits;
}

long add (long a, long b) {
	return ((a%digits)+(b%digits))%digits;
}

int main() {
	const int limit = 1000;
	long sum = 0;
	for (long i = 1; i < limit; i++) {
		long k = i;
		for (int j = 1; j < i; j++) k = mult(k,i);
		sum = add(sum, k);
	}
	cout << "Last 10 digits: " << sum << endl;
}
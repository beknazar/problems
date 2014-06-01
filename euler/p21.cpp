#include <vector>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <stdio.h>
#include <sstream>
using namespace std;
const int size = 10000;
int arr[size*10];

bool isPrime(int n) {
	if (n == 2) return 1;
	if (n%2 == 0) return 0;
	for (int i = 3; i*i <= n; i+=2) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int d(int n) {
	if (n < size && arr[n]) return arr[n]; // memoization
	int sum = 1, c = 0, last, k = n;
    for (int i = 2; i <= n;) {
		if (n % i == 0) {
			last = i;
			n /= i;
			c++;
			// cout << "i: " << i << endl;
		}
		else {
			if (c) {
				// cout << "c: " << c << " last: " << last << endl;
				int s = 1;
				for (int j = 1; j <= c; j++) {
					s += pow(last, j);
					// cout << s << " ";
				}
				// cout << endl;
				sum *= s;
			}
			c = 0;
			i++;
		}
	}
	if (c) {
		int s = 1;
		for (int j = 1; j <= c; j++) {
			s += pow(last, j);
		}
		sum *= s;
	}
	if (n > 1) {
		sum *= (1 + n);
	}
	arr[k] = sum - k;
	return sum - k;
}
 
int main() {
	for (int i = 2; i < size*10; i++) {
		arr[i] = 0;
	}
	long sum = 0, sumOfDivisors;
	for (int i = 2; i < size; i++) {	
		if (arr[i] == 0) {
			sumOfDivisors = d(i);
			if (sumOfDivisors != i && d(sumOfDivisors) == i) {
				sum += i + sumOfDivisors;
				cout << i << endl;
			}
		}
	}
	cout << sum << endl;
	cout << d(1184) << " : " << d(1210) << endl;
}
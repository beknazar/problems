#include <vector>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <stdio.h>
#include <sstream>
#include <limits.h>
#include <sys/time.h>
using namespace std;
const int mod = 1000000;

int fact (int n) {
	if (n == 0 || n == 1) return 1;
	return n * fact(n - 1);
}

long c (int n, int r) {
	if (n > 2*r) {
		int temp = r;
		r = n - r;
	}
	long mult = n;
	for (int i = n-1; i > r; i--) mult *= i;
	mult /= fact(n - r);
	return mult;
}

int main() {
	struct timeval stop, start;
	gettimeofday(&start, NULL);
	//do stuff
	const int limit = 100;
	int count = 0;
	for (int n = 23; n <= limit; n++) {
		for (int i = 1; i <= n; i++) {
			if (c(n, i) > mod) {
				count += (n -2*i+1);
				break;
			}
		}
	}
	gettimeofday(&stop, NULL);
	printf("took %lu milliseconds\n", stop.tv_usec - start.tv_usec);
	printf("%s %d\n", "Number of values of ncr above 1000000 is", count);
}
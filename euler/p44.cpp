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

bool check (int x) {
	double k = (sqrt(1 + 24*x) + 1.0)/6.0;
	return (k == (int)k);
}


int main() {
	const int limit = 10;
	int p, n = 1, q, d;
	bool notFound = 1;
	while (notFound) 	{
		n++;
		p = (n*(3*n-1))/2;
		// cout << "P: " << p << endl;
		for (int i = n - 1; i > 0; i--) {
			q = (i*(3*i-1))/2;
			// cout << "Q: " << q << endl;
			if (check (p - q) && check (p + q)) {
				d = p - q;
				notFound = 0;
				break;
			}
		}
	}
	cout << "Minimised difference is: " << d << endl;
}
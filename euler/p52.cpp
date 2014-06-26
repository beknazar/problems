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

bool check (int a, int b) {
	ostringstream ss, tt;
	ss << a;
	string strA = ss.str();
	sort(strA.begin(), strA.end());
	tt << b;
	string strB = tt.str();
	sort(strB.begin(), strB.end());
	return strA == strB; 
}

int main() {
	for (int x = 12; ; x+=3) {
		if (check (x, 2*x) && check (2*x, 3*x) && check (3*x, 4*x) && check (4*x, 5*x) && check (5*x, 6*x)) {
			cout << x << endl;
			break;
		}
	}
}
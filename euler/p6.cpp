#include <iostream>
#include <cmath>

using namespace std;


int main() {
	// unsigned long long n = 600851475143;
	int n = 100;
	cout << fixed;
	cout << pow((n*(n+1)/2),2) - (n*(n+1)*(2*n+1)/6) << endl;
}
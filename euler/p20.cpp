#include <iostream>
#include <sstream>

using namespace std;

double fact(int n) {
	if (n == 0) return 1;
	return n*fact(n-1);
}

int main() {
	ostringstream s;
	long double n = fact(100);
	s << fixed << n;
	string str = s.str();
	cout << str << endl;
	int sum = 0, i = 0;
	// str = "1993.0";
	while (str[i] != '.') {
		sum += str[i] - '0';
		i++;
	}
	cout << sum << endl;
	return 0;
}

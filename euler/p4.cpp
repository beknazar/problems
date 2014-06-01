#include <iostream>
#include <sstream>

using namespace std;

template <typename T>
string numberToString (T Number)
{
	ostringstream ss;
	ss << Number;
	return ss.str();
}

bool isPalindrome(string n) {
	for (int i = 0; i < n.length() / 2; i++) {
		if (n[i] != n[n.length() - i - 1]) return 0; 
	}
	return 1;
}

int main() {
	int n = 999*999;
	// for (int i = 0; i < 20; i++) {
	// 	cout << n  << " ";
	// 	n -= 999;
	// }
	int max = 0;
	for (int i = 999; i > 100; i--) {
		for (int j = 999; j > 100; j--) {
			int product = i*j;
			if (isPalindrome(numberToString(product)) && max < product) {
				cout << "max: " << i << "X" << j << " = " << product << endl;
				max = product;
			}
		}
	}
	// string st = numberToString(12331);
	// cout << "YES?" << isPalindrome(st) << endl;
	// cout << st << endl;
}
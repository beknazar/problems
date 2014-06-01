#include <iostream>
#include <vector>

using namespace std;

typedef vector<char> bignum;

void Double(bignum & num) {
	int carry = 0;
	for (bignum::iterator p = num.begin(); p != num.end(); p++) {
		*p *= 2;
		*p += carry;
		carry = (*p >= 10);
		*p -= carry * 10;
	}
	if (carry != 0) num.push_back(carry);
}

void Display(bignum & num) {
	for (bignum::reverse_iterator p = num.rbegin(); p != num.rend(); p++) cout << static_cast<int>(*p);
}

int main() {
	bignum num;
	num.push_back(1);
	for (int i = 0; i < 1000; i++) Double(num);
	Display(num);
	
	cout << endl;
	return 0;
}

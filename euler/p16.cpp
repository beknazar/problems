#include <iostream>
#include <cmath>

using namespace std;

long sum (double x) {
	// unsigned long long x = pow(2, n);
	long sum = 0;
	while(x != 0) {
		sum += fmod(x, 10);
		x /= 10;
	}
	return sum;
}
int main() {
	int n = 1000;
	BigInteger x = pow(2, n);
	// cout << "N: " << 15 << " sumOfDigits: " << sum(15) << endl;
	// for (int n = 15; n < 30; n++)
	cout << "N: " << n << " sumOfDigits: " << sum(x) << endl;
	// int i = 256;
	// cout << "X: " << i << " sumOfDigits: " << sum(i) << endl;
	// cout << "X2: " << i*i << " sumOfDigits: " << sum(i*i) << endl;
	// int in = 0;
	// for (int i = 2; i <= pow(2, 20); i*=2) {
	// 	cout << "X: " << i << " sumOfDigits: " << sum(i) << " in: " << ++in << endl;
	// 	// cout << "X2: " << i*i << " sumOfDigits: " << sum(i*i) << endl;
	// }
	cout << fixed;
	cout << "X: " << x << endl;
	// cout << "fmod(x, 10): " << (int)fmod(x, 10) << endl;
	// string num = "1993";
	string num = "10715086071862673209484250490600018105614048117055336074437503883703510511249361224931983788156958581275946729175531468251871452856923140435984577574698574803934567774824230985421074605062371141877954182153046474983581941267398767559165543946077062914571196477686542167660429831652624386837205668069376";
	int len = num.length(), sum = 0;
	for (int i = 0; i < len; i++) {
		sum += num[i] - '0';
	}
	cout << sum << endl;
	cout << sizeof(long);
}
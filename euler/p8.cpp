#include <iostream>

using namespace std;

int main() {
	string input = "", line;
	while(cin) {
		cin >> line;
		input += line;
	}

	int max = 0;
	for (int i = 0; i < input.length() - 5; i++) {
		int product = (input[i]-'0')*(input[i+1]-'0')*(input[i+2]-'0')*(input[i+3]-'0')*(input[i+4]-'0');
		if (product > max) {
			max = product;
		}
	}
	cout << max << endl;
	cout << input << endl;
}
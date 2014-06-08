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

class euler43 {
private:
	int * primes;
	long res;

	long val (const string & s) {
		long sum = 0, k = 1;
		for (int i = s.length() - 1; i >= 0; i--) {
			sum += (s[i] - '0') * k;
			k *= 10;
		}
		return sum;
	}

	bool check (string s) {
		int k = 6, sum;
		for (int i = 7; i > 0; i--) {
			sum = val(s.substr(i, 3));
			if (sum % primes[k--]) return 0;
		}
		return 1;
	}
public:

	euler43 () {
		primes = new int[7];
		primes[0] = 2;
		primes[1] = 3;
		primes[2] = 5;
		primes[3] = 7;
		primes[4] = 11;
		primes[5] = 13;
		primes[6] = 17;
		res = 0;
	}

	~euler43 () {
		delete [] primes;
	}

	void nextPerm (string s, int currentFocus) {
		if (currentFocus == s.length() - 1) {
			if (check (s)) {
				res += val(s);
				cout << val(s) << endl;
			}
			return;
		}

		nextPerm (s, currentFocus + 1);

		for (int i = currentFocus + 1; i < s.length(); i++) {
			char temp = s[currentFocus];
			s[currentFocus] = s[i];
			s[i] = temp;

			nextPerm (s, currentFocus + 1);
		}
	}

	long getResult () {
		return res;
	}
};

int main() {
	euler43* problem = new euler43();
	problem -> nextPerm ("0123456789", 0);

	cout << "Sum of such numbers is: " << problem -> getResult() << endl;
}
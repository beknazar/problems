#include <iostream>
#include <map>
using namespace std;

bool isLeap(int year) {
	if (year % 100 == 0) return year % 400 == 0;
	return year % 4 == 0;
}

int main() {
	// cout << 365 % 7;
	int d = 2, k, count = 0;
	int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	for (int y = 1901; y < 2001; y++) {
		for (int i = 0; i < 12; i++) {
			int days = months[i];
			if (i == 2 && isLeap(y)) days++; 
			if ((d+=days) % 7 == 0) count++;
		}
	}
	cout << count << endl;
}

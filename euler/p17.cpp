#include <iostream>
#include <cmath>

using namespace std;
const int size = 27;
int words[size];


int sum (int);

int main() {
	for (int i = 0; i < size; i++) words[i] = 0;

	words[1] = 3;
	words[2] = 3;
	words[3] = 5;
	words[4] = 4;
	words[5] = 4;
	words[6] = 3;
	words[7] = 5;
	words[8] = 5;
	words[9] = 4;
	words[10] = 3;
	words[11] = 6;
	words[12] = 6;
	words[13] = 8;
	words[14] = 8;
	words[15] = 7;
	words[16] = 7;
	words[17] = 9;
	words[18] = 8;
	words[19] = 8;
	words[20] = 6;
	words[30] = 6;
	words[40] = 5;
	words[50] = 5;
	words[60] = 5;
	words[70] = 6;
	words[80] = 7;
	words[90] = 6;
	int s = 0;
	for (int i = 1; i < 1000; i++) {
		s += sum(i);
	}
	cout << s + 11 << endl;
}

int sum(int x) {
	if (x < size && words[x] != 0) return words[x];
	if (x < 100) return words[x%10] + words[x-x%10]; 
	int k = x/100;
	if (x - k*100 == 0) return 7 + words[k];
	return 10 + words[k] + sum(x - k*100);
}
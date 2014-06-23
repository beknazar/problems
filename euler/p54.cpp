#include <vector>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <stdio.h>
#include <sstream>
#include <limits.h>
#include <sys/time.h>
using namespace std;

int value (const string& hand) {
	int arr[5];
}

bool check (const string& card) {
	cout << card.substr(0, 14) << " : " << card.substr(15) << endl;
	return value (card.substr(0, 14)) > value (card.substr(15));
}

int main() {
	//do stuff
	const int lines = 10000;
	string card;
	int count = 0;
	while (getline(cin, card)) {
		// cout << card << endl;
		check (card);
	}

	// printf("%s %d\n", "Number of values of ncr above 1000000 is", count);
}
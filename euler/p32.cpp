#include <vector>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <stdio.h>
#include <sstream>
using namespace std;

bool check (int n, int * nums) {
	while (n > 0) {
		int k = n%10;
		if (k == 0) return 0;
		if (nums[k - 1] == 0) return 0;
		nums[k - 1] = 0;
		n /= 10;
	}
	return 1;
}

void update (int n, int * nums) {
	while (n > 0) {
		int k = n%10;
		n /= 10;
		nums[k - 1] = 0;		
	}
}

void reset (int * nums) {
	for (int i = 0; i < 9; i++) nums[i] = 1;
}

int main() {
	int nums[9];
	for (int i = 1; i < 9999; i++) {
		reset(nums);
		if (check (i,nums)) {
			for (int j = 1; j < 9999; j++) {
				if (check (j, nums)) {
					// cout << i << " : " << j << endl;
					if (check (i*j, nums)) cout << "i: " << i << " j; " << j << " | i*j: " << i*j << endl;
					// reset(nums);
				}
				reset(nums);
				update(i, nums);
			}
		}
	}
	// reset(nums);
	// cout << check (42, nums) << endl;
	// update (42, nums);
	// cout << check (23, nums) << endl;
}
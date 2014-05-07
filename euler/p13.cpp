#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int main() {
	int nums = 100, dig = 50;
	int** arr = new int*[nums];
	for (int i = 0; i < nums; i++) arr[i] = new int[dig];

	for (int i = 0; i < nums; i++) {
		for (int j = 0; j < dig; j++) cin >> arr[i][j];
	}

	unsigned long long sum = 0;
	unsigned long* sum10 = new unsigned long[nums];

	for (int i = 0; i < nums; i++) {
		sum10[i] = 0;
		for (int j = 11; j >= 0; j--) {
			sum10[i] += arr[i][j] * pow(10, 11-j);
		}
		sum += sum10[i];
	}
	// int temp, rem = 0;
	// for (int i = 0; i < nums; i+=2) {
	// 	for (int j = 10; i < dig; i++) {
	// 		temp = arr[i][j] + arr[i+1][j];
	// 		if (temp < 10 && arr[i][j+1] + arr[i+1][j+1] >= 10) {
	// 			if (temp + 1 < 10) {
	// 				break;
	// 			}
	// 		}
	// 		else {
	// 			rem++;
	// 			break;
	// 		}
	// 	}
	// }
	
	// for (int i = 1; i < nums; i+=2) {
	// 	cout << arr[i][9] << endl;
	// }
	cout << sum << endl;

	cout << log10(LONG_MAX) << endl;
}

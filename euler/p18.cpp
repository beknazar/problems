#include <iostream>
#include <map>
using namespace std;

int main() {
	int size, n;
	cin >> size;
	int** arr = new int*[size];
	for (int i = 0; i < size; i++) arr[i] = new int[size];
	/* Input -> array */
	for (int i = 0; i < size; i++) {
		for (int j = 0 ; j <= i; j++) {
			cin >> arr[i][j];
		}
	}

	int max;
	for (int i = size-1; i > 0; i--) {
		for (int j = 0; j <= i; j++) {
			int n = arr[i][j]+arr[i-1][j];
			if (max < n) max = n; 
			if (j < size-1) {
				n = arr[i][j+1]+arr[i-1][j];
				if (max < n) max = n;
			}
			arr[i-1][j] = max;
			max = 0;
		}
	}

	// for (int i = 0; i < size; i++) {
	// 	for (int j = 0 ; j <= i; j++) {
	// 		cout << arr[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	cout << arr[0][0] << endl;
}

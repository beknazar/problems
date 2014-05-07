#include <iostream>

using namespace std;

int m, n;
int** grid;

int val(int i, int j) {
	if (i >=0 && j >= 0 && i < m && j < n) return grid[i][j];
	return 0;
}

int main() {
	cin >> m >> n;

    grid = new int*[m];
    for (int i = 0; i < m; i++) grid[i] = new int[n];


	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	int max = 0, product;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			product = val(i, j)*val(i+1, j)*val(i+2, j)*val(i+3, j);
			if (product > max) max = product;
			product = val(i, j)*val(i, j+1)*val(i, j+2)*val(i, j+3);
			if (product > max) max = product;
			product = val(i, j)*val(i+1, j+1)*val(i+2, j+2)*val(i+3, j+3);
			if (product > max) max = product;
		}
	}
	cout << max << endl;

}

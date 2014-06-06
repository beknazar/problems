#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int fact(int n) {
	if (n == 0) return 1;
	return n*fact(n-1);
}

int main() {
	const int size = 10;
	int perm[size] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	string res = "";
	int remain = 1000000 - 1;

	vector<int> numbers;
	for (int i = 0; i < size; i++) {
		numbers.push_back(i);
	}

	for (int i = 1; i < size; i++) {
		int j = remain / fact(size - i);
		remain = remain % fact(size - i);
		res += numbers.at(j) + '0';
		numbers.erase(numbers.begin() + j);
		if (remain == 0) break;
	}

	for (int i = 0; i < numbers.size(); i++) res += numbers.at(i) + '0';

	cout << res << endl;
}


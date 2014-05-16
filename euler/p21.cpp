#include <iostream>
#include <sstream>

using namespace std;

template<typename T>
void quicksort(T* a, int left, int right) {
	int i = left, j = right;
	T tmp, pivot = a[left];
	while (i <= j) {
		while (a[i] < pivot) i++;
		while (a[j] > pivot) j--;
		if (i <= j) {
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
			j--;
		}
	}

	if (left < j) quicksort(a, left, j);
	if (i < right) quicksort(a, i, right);

}

int main() {
	const int size = 5163;
	string* list = new string[size];
	string in;
	cin >> in;
	istringstream ss(in);
	string token;
	int k = 0;
	while(getline(ss, token, ',')) {
		// cout << token.substr(1, token.length() - 2) << endl;
		list[k++] = token.substr(1, token.length() - 2);
	}
	quicksort(list, 0, size - 1);
	long sum = 0;
	int s = 0;
	k = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < list[i].length(); j++) s += list[i][j] - 64;
		sum += (i+1)*s;
		s = 0;
	}
	cout << sum << endl;
}

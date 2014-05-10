#include <iostream>
#include <map>
using namespace std;

int main() {
	
	int num, max = 0;
	long j;
	const int size = 1000000;

	int* arr = new int [size + 1];
	for (int i = 0; i < size; i++) arr[i] = 0;
	arr[1] = 1;

	for (int i = 2; i < size; i++) {
		int count = 0;
		j = i;
		while (j != 1 && j >= i) {
			count++;
			if (j % 2 == 0) j /= 2;
			else j = 3*j + 1;
		}
		arr[i] = count + arr[j];

		if(arr[i] > max)  {
			max = arr[i];
			num = i;
		}
	}
	cout << "max: " << max << " num: " << num << endl;
}

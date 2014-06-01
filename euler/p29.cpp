#include <iostream>
#include <cmath>
#include <set>
using namespace std;

int main() {
	const int limit = 100;
	set<double> s;
	for (int i = 2; i <= limit; i++) {
		for (int j = 2; j <= limit; j++) {
			s.insert(pow(i, j));
		}
	}
	cout << s.size() << endl;
}
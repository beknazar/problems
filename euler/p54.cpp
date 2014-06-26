#include <vector>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <stdio.h>
#include <sstream>
#include <limits.h>
#include <list>
using namespace std;

int index (char c) {
	int k = c - '0';
	if (k > 1 && k < 10) return k - 2;
	switch (c) {
		case 'C':
			return 0;
		case 'D':
			return 1;
		case 'H':
			return 2;
		case 'S':
			return 3;
		case 'T':
			return 8;
		case 'J':
			return 9;
		case 'Q':
			return 10;
		case 'K':
			return 11;
		case 'A':
			return 12;
		default:
			return 13;
	}
	return -1;
}

int value (const string& hand, int & val) {
	list<int>* ls = new list<int>[4];
	list<int>* ls2 = new list<int>[13];
	for (int i = 1; i < 14; i+=3) {
		ls[index(hand[i])].push_back(index(hand[i - 1]));
		ls2[index(hand[i - 1])].push_back(index(hand[i]));
	}
	for (int i = 0; i < 4; i++) ls[i].sort();
	for (int i = 0; i < 4; i++) {
		// cout << "\n" << i << ":" << endl;
		// for (list<int>::iterator it = ls[i].begin(); it != ls[i].end(); it++)
		// 	cout << ' ' << *it;
	}
	for (int i = 0; i < 4; i++)
		if (ls[i].size() == 5 && ls[i].front() == 8) return 1; // Royal flush
	for (int i = 0; i < 4; i++)
		if (ls[i].size() == 5 && ls[i].front() - ls[i].back() == 4) {
			val = ls[i].front();
			return 2; // Straight flush 
		}
	for (int i = 0; i < 13; i++) {
		if (ls2[i].size() == 4) {
			val = i;
			return 3; // Four of a Kind
		}
	}
	for (int i = 0; i < 13; i++)  {
		if (ls2[i].size() == 3) {
			for (int j = 0; j < 13; j++)
				if (j != i && ls2[j].size() == 2) {
					val = i;
					return 4; // Full House
				}
		}
	}
	for (int i = 0; i < 4; i++)
		if (ls[i].size() == 5) {
			val = i;
			return 5; // Flush
		}
	for (int i = 0; i < 13; i++) {
		if (ls2[i].size() == 1) {
			int j = i + 1;
			while (j < 13 && ls2[j].size() == 1) j++;
			if (j - i == 5) {
				val = i;
				return 6; // Straight
			}
		}
	}
	for (int i = 0; i < 13; i++)
		if (ls2[i].size() == 3) {
			val = i;
			return 7; // Three of a Kind
		}
	for (int i = 0; i < 13; i++) {
		if (ls2[i].size() == 2) {
			for (int j = i + 1; j < 13; j++)
				if (ls2[j].size() == 2) {
					val = j*10 + i;
					return 8; // Two Pairs
				}
		}
	}
	for (int i = 0; i < 13; i++) 
		if (ls2[i].size() == 2) {
			val = i;
			return 9; // One Pair
		}
	for (int i = 12; i >= 0; i--)
		if (ls2[i].size() > 0) {
			val = i;
			return 10; // Highest card
		}


	return -1;
}

bool check (const string& card) {
	// cout << card.substr(0, 14) << " : " << card.substr(15) << endl;
	int val, val2, c = 0;
	if (value (card.substr(0, 14), val) < value (card.substr(15), val2)) return 1;
	else if (value (card.substr(0, 14), val) == value (card.substr(15), val2))
		return 0;
	return val > val2;
}

int main() {
	const int lines = 10000;
	string card;
	int count = 0, val = 0;
	while (getline(cin, card)) {
		// cout << check (card) << endl;
		count += check (card);
	}
	cout << count << endl;
	cout << check ("2H 2D 4C 4D 4S 3C 3D 3S 9S 9D") << endl;
	cout << value ("3C 3D 3S 9S 9D", val);
	cout << " ; " << val << endl;
	// check ("9C JD 7C 6D TC 6H 6C JC 3D 3S");
	// printf("%s %d\n", "Number of values of ncr above 1000000 is", count);
}
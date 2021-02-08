#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
using namespace std;

int main() {

	vector<int> anser;

	for (int i = 0; i < 9; ++i) {
		int value;
		cin >> value;
		anser.push_back(value);
	}

	int index, maxValue;
	index = maxValue = 0;

	for (int i = 0; i < 9; ++i) {
		if (anser[i] > maxValue) {
			maxValue = anser[i];
			index = i;
		}
	}

	cout << maxValue << endl << index+1 << endl;
}
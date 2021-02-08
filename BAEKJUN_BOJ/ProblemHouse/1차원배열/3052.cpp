#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
using namespace std;

int main() {

	int anser[43];
	int ret = 10;
	memset(anser, -1, sizeof anser);

	for (int i = 0; i < 10; ++i) {
		int value;
		cin >> value;

		anser[value % 42]++;
	}
		
	for (int i = 0; i < 42; ++i) {
		if (anser[i] == -1) {
			anser[i] = 0;
		}
		ret = ret - anser[i];
	}

	cout << ret << endl;
}
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
using namespace std;

int main() {

	int anser[10] = { 0 };
	int ret = 1;

	for (int i = 0; i < 3; ++i) {
		int value;
		cin >> value;
		ret = ret * value;
	}

	string result = to_string(ret);

	for (int i = 0; i < result.size(); ++i) {
		anser[result[i] - '0']++;
	}

	for (int i = 0; i < 10; ++i) {
		cout << anser[i] << '\n';
	}

}
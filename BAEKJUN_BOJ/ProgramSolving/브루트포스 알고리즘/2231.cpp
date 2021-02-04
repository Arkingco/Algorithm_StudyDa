#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
using namespace std;

int main() {

	int n, i;
	cin >> n;

	bool check = false;
	for (i = 0; i < n; ++i) {
		int ret = 0;

		string number = to_string(i);
		for (int j = 0; j < number.size(); ++j) {
			ret = ret + (number[j] - '0');
		}
		ret = ret + i;

		if (ret == n) {
			check = true;
			break;
		}
	}

	if (check) {
		cout << i << endl;
	}
	else {
		cout << "0" << endl;
	}
}
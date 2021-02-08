#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

int main() {

	int n = 5;
	vector<int> anser(5);

	int ret = 0;
	for (int i = 0; i < n; ++i) {
		cin >> anser[i];
		ret = ret + (anser[i] * anser[i]);
	}

	cout << ret % 10 << endl;
}
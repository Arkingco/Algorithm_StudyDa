#include<algorithm>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<deque>
#include<map>
#include<stack>
using namespace std;

int main() {

	int n, k;
	cin >> n >> k;

	stack<int> S;
	for (int i = 0; i < n; ++i) {
		int value;
		cin >> value;
		S.push(value);
	}

	int count = 0;
	while (!S.empty()) {
		int value = k / S.top();
		if (value != 0) {
			k = k - (S.top() * value);
		}
		count = count + value;

		S.pop();
	}

	cout << count << endl;
}
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
#include<math.h>
#include<stack>
#include<queue>
#include<stdio.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	stack<int> anser;
	for (int i = 0; i < n; ++i) {
		int value;
		cin >> value;

		if (value == 0) {
			if (!anser.empty()) {
				anser.pop();
			}
		}
		else {
			anser.push(value);
		}
	}

	int result = 0;
	while (!anser.empty()) {
		int value = anser.top();
		anser.pop();

		result = result + value;
	}

	cout << result << '\n';
}
    
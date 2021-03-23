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
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		map<string, int> pattern;
		while (n--) {

			string name, dress;
			cin >> name >> dress;

			if (!pattern[dress]) {
				pattern[dress] = 1;
			}
			else {
				pattern[dress]++;
			}

		}

		int result = 1;
		for (auto i = pattern.begin(); i!=pattern.end(); ++i) {
			result = result * (i->second + 1);
		}

		cout << result - 1 << endl;
	}
}
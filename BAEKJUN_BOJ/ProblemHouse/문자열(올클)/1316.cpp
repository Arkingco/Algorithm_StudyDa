#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
using namespace std;

int main() {
	
	int T;
	cin >> T;

	int ret = 0;
	while (T--) {
		string a;
		cin >> a;

		bool check = false;
		for (int i = 0; i < a.size(); ++i) {
			for (int j = i + 1; j < a.size(); ++j) {
				if (a[i] == a[j] && a[j - 1] != a[i]) check = true;
			}
		}

		if (!check) {
			ret++;
		}
	}

	cout << ret << '\n';
}
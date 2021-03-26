#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> member(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> member[i];
	}
	sort(member.begin(), member.end());

	int result = 0;
	int time = 0;
	for (int i = 0; i < n; ++i) {
		time = time + member[i];
		result = result + time;
	}

	cout << result << '\n';
}

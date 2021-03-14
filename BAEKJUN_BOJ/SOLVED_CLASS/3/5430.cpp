#include<algorithm>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<deque>
#include<map>
using namespace std;

deque<int> result;

void call(string p) {
	for (int i = 0; i < p.size(); ++i) {
		if (p[i] == 'R') {
			if (result.empty()) continue;

			reverse(result.begin(), result.end());
		}
		else if (p[i] == 'D') {
			if (result.empty()) {
				cout << "error" << endl;

				return;
			}

			result.pop_front();
		}
	}

	if (result.empty()) {
		cout << "[]" << '\n';
		return;
	}
	cout << "[";
	for (int i = 0; i < result.size()-1; ++i) {
		cout << result[i] << ",";
	}
	cout << result[result.size() - 1];
	cout << "]" << '\n';
}

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	while (t--) {
		string p;
		cin >> p;

		int n;
		cin >> n;
		string value;
		cin >> value;
		

		int cost = 1;
		int firstValue = 0;
		for (int i = value.size() - 2; i >= 1; --i) {
			if (value[i] == ',') {
				result.push_front(firstValue);

				firstValue = 0;
				cost = 1;

			}
			else {
				int a = cost * ((int)value[i] - 48);
				firstValue = firstValue + a;
				cost = cost * 10;
			}
		}	
		// 만약 [] 이 비어있다면 추가 하면 안됨
		if(value.size() > 2)result.push_front(firstValue);
		
		call(p);

		result.clear();
	}


}
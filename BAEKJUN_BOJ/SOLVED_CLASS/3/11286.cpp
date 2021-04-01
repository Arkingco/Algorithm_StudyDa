#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;


int ABS(int value) {
	return value < 0 ? -value : value;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	priority_queue<int> q;
	for (int i = 0; i < n; ++i) {
		int value;
		cin >> value;

		if (value == 0) {
			if (q.empty()) {
				cout << "-1" << '\n';
			}
			else {
				
			}
		}
		else {
			q.push(-(abs(value)));
		}
		


	}
	
	
	
}   
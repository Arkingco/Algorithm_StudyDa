#include<algorithm>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
using namespace std;

int main()
{	
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	priority_queue<int> pq;

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int value;
		cin >> value;

		if (value == 0) {
			if (pq.empty()) {
				cout << "0" << '\n';
			}
			else {
				int front = pq.top();
				pq.pop();
				cout << -front << '\n';
			}
		}
		else {
			pq.push(-value);
		}
	}

	
}

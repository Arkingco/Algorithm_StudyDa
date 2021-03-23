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

const int INF = 98765431;

int absol(int value) {
	return value < 0 ? -(value) : value;
}

int main() {
	int t;
	cin >> t;
	
	bool visited[103];
	while (t--) {
		int n;
		cin >> n;

		
		vector<pair<int, int> > adj[103];
		vector<pair<int, int>> path;
		bool check = false;
		memset(visited, false, sizeof visited);
		
		for (int i = 0; i < n + 2; ++i) {
			int a, b;
			cin >> a >> b;
			path.push_back({ a, b });
		}

		for (int i = 0; i < n + 2; ++i) {
			for (int j = 0; j < n + 2; ++j) {
				if (i == j) continue;
				int val = absol((path[i].first - path[j].first)) + absol((path[i].second - path[j].second));
				adj[i].push_back({ val, j });
			}
		}

		queue<int> q;
		q.push(0);
		visited[0] = true;
		while (!q.empty()) {
			int here = q.front();
			q.pop();

			if (here == n + 1) {
				check = true;
				break;
			}

			for (int i = 0; i < adj[here].size(); ++i) {
				int next = adj[here][i].second;
				int nextVal = adj[here][i].first;
				if (!visited[next] && nextVal <= 1000) {
					visited[next] = true;
					q.push(next);
				}
			}

		}

		if (check) {
			cout << "happy" << '\n';
		}
		else {
			cout << "sad" << '\n';
		}

	}
}
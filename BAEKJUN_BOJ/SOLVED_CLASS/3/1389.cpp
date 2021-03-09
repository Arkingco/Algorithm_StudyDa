#include<algorithm>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;

int meetNumber[101][101] = { 0 };
int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n + 1, vector<int>(0, 0));
	queue<int> q;
	pair<int, int> mini = { 0, 9999 };

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;

		// 양방향 간선
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 1; i <= n; ++i) {
		bool visited[5001] = { false };
		int meetingNumber = 1;

		q.push(i);
		visited[i] = true;
		while (!q.empty()) {
			int here = q.front();

			q.pop();
			for (int next = 0; next < adj[here].size(); ++next) {
				int there = adj[here][next];

				if (!visited[there]) {
					visited[there] = true;
					meetNumber[i][there] = meetNumber[i][here] + 1;
					q.push(there);
				}
			}
		}
	}
	
	for (int i = 1; i <= n; ++i) {

		int minValue = 0;
		for (int j = 1; j <= n; ++j) {
			minValue = minValue + meetNumber[i][j];
		}

		if (mini.second > minValue) {
			mini.first = i;
			mini.second = minValue;
		}
	}

	cout << mini.first << endl;
}

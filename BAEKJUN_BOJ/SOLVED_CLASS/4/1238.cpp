#include<algorithm>
#include<string.h>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
using namespace std;
typedef pair<int, int> pii;

const int MAX_DIST = 1003;
const int INF = 987654321;
// 다익스트라
vector<vector<pii> > adj;
int dist[MAX_DIST];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m, x;
	cin >> n >> m >> x;
	for (int i = 0; i < MAX_DIST; ++i) {
			dist[i] = INF;
	}

	adj = vector<vector<pii> >(n+1);

	for (int i = 0; i < m; ++i) {
		int start, stop, value;
		cin >> start >> stop >> value;
		adj[start].push_back({ stop, value });
	}

	priority_queue<pii> q;
	dist[x] = 0;
	q.push({ 0, x });

	while (!q.empty()) {
		int here = q.top().second;
		q.pop();
		cout << here << endl;
		for (int i = 0; i < adj[here].size(); ++i) {
			int next = adj[here][i].first;
			int nextVal = adj[here][i].second;

			if (dist[here] + nextVal < dist[next]) {
				dist[next] = dist[here] + nextVal;
				q.push({ -nextVal, next });
			}

		}
	}

	for (int i = 1; i <= n; ++i) {
		cout << dist[i] << " ";
	}
}
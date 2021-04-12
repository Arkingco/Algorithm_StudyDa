#include<algorithm>
#include<string.h>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
using namespace std;

const int MAX_SIZE = 100003;

bool visited[100003];
vector<pair<int, int>> adj[MAX_SIZE];

int result_dist = 0;
int far_vertex = 0;
int second_V = 0;

void init() {
	memset(visited, false, sizeof visited);
	result_dist = 0;
	far_vertex = 0;
	second_V = 0;
}

void dfs(int here, int far_value) {
	
	visited[here] = true;

	if (result_dist < far_value) {
		far_vertex = here;
		result_dist = far_value;
	}

	for (int i = 0; i < adj[here].size(); ++i) {
		int next = adj[here][i].first;
		int next_val = adj[here][i].second;

		if (!visited[next]) {
			dfs(next, far_value + next_val);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int from;
		cin >> from;

		while (true) {
			int to, val;

			cin >> to;
			if (to == -1) {
				break;
			}
			cin >> val;

			adj[from].push_back({ to,val });
		}
	}
	
	// 임의의 한 점에서 제일 거리가 먼 정점을 구하고
	// 그 정점에서 가장 먼 정점과의 거리를 구하면 트리의 지름이 된다.
	init();
	dfs(1, 0);
	int first_vertex = far_vertex;

	init();
	dfs(first_vertex, 0);
	
	cout << result_dist << '\n';

}
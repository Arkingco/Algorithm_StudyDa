#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> graph[51];
int score[51];
int n;

void bfs(int start) {
	bool visited[51] = { 0, };
	int depth[51] = { 0, };
	
	queue<int> q;
	q.push(start);
	
	visited[start] = true;
	depth[start] = 0;

	while (!q.empty()){
		int x = q.front();
		q.pop();
		for (int i = 0; i < graph[x].size(); i++){
			int y = graph[x][i];
			if (!visited[y]) {
				q.push(y);
				visited[y] = true;
				depth[y] = depth[x] + 1;
			}
		}
	}
	
	int maxDepth = depth[1];
	for (int i = 2; i <= n; i++){
		maxDepth = max(maxDepth, depth[i]);
	}
	score[start] = maxDepth;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    
	cin >> n;
	int from=0, to=0;
	while (true){
		cin >> from >> to;
		if (from == -1 && to == -1) break;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	for (int i = 1; i <= n; i++){
		bfs(i);
	}

	int maxScore = score[1];
	for (int i = 2; i <= n; i++){
		maxScore = min(maxScore, score[i]);
	}

	int count = 0;
	for (int i = 1; i <= n; i++){
		if (score[i] == maxScore) count++;
	}
	cout << maxScore << " " << count << "\n";

	for (int i = 1; i <= n; i++) {
		if (score[i] == maxScore) cout<<i<<" ";
	}
}
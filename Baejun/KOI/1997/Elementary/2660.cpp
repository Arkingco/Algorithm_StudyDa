#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int > > adj;
int n;
vector<int> visited;
vector<int> friendScore;
vector<int> result;
void bfs(int start) {
	queue<int> q;
	q.push(start);
	
	int friendNum = 0;
	
	visited[start] = 1;
	friendScore[start] = 0;
	while(!q.empty()) {
		int here = q.front();
		q.pop();
		
		for(int i=0; i<adj[here].size(); ++i) {
			int next = adj[here][i];
			
			if(visited[next] == 0) {
				friendScore[next] = friendScore[here] + 1;
				visited[next] = 1;
				q.push(next);
			}
		}
	}
	
	int maxDepth = -1;
	for(int i=1; i<=n; ++i) {
		maxDepth = max(maxDepth, friendScore[i]);
	}
	result.push_back(maxDepth);
}
int main() {
	cin >> n;
	
	adj = vector<vector<int> > (n+1,vector<int>(0,0));
	friendScore = vector<int>(n+1,0);
	result = vector<int>(0);
	int a = 0;
	int b = 1;
	while(true) {
		cin >> a >> b;
		
		if(a == b) break;
		
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i=1; i<=n; ++i) {
		visited = vector<int>(n+1,0);
		bfs(i);
	}
	
	int minNum = 99999;
	for(int i=0; i<result.size(); ++i) {
		minNum = min(minNum, result[i]);
	}
	
	vector<int> anser;
	for(int i=0; i<result.size(); ++i) {
		if(minNum == result[i]) anser.push_back(i+1);
	}
	
	cout << minNum << " " << anser.size() << '\n';
	for(int i=0; i<anser.size(); ++i) {
		cout << anser[i] << " ";
	}
}

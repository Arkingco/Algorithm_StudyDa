#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int INF = 987654321;
int V, E;
int delay[500];
vector<vector<int> > adj;

// 입력 받을 때 1부터 시작하는 정점 번호를 0부터 시작하도록 변경했다고 가정한다.
void solbe() {
	// 모든 정점들을 예상 시간 별로 정렬한다.
	vector<pair<int, int> > order;
	for(int i=0; i<V; ++i) {
		order.push_back({delay[i],i});
	}
	sort(order.begin(), order.end());
	// 정점을 하나도 거치지 않고 얻을 수 있는 최단 경로
	for(int i=0; i<V; ++i) {
		for(int j=0; j<V; ++j) {
			if(i == j)
				W[i][j] = 0;
			else
				W[i][j] = adj[i][j];
		}
	}
	int ret = INF;
	
	for(int k=0; k<V; ++k ) {
		// k번째로 예상 시간이 적게 걸리는 정점 w까지를 지나서 얻을 수 있는 최단거리
		int w = order[k].second;
		for(int i=0; i<V; ++i)
			for(int j=0; j<V; ++j) {
				adj[i][j] = min(adj[i][j],adj[i][w] + adj[w][j]);
				W[i][j] = min(adj[i][w] + delay[w] + adj[w][j], W[i][j]);
			} 
	}
	
}

void init() {
	cin >> V >> E;
	for(int i=0; i<V; ++i) {
		cin >> delay[i];
	}
	
	adj = vector<vector<int> >(V+1, vector<int>(V+1, 0));
	for(int i=0; i<E; ++i) {
		int from, to, val;
		cin >> from >> to >> val;
		adj[from][to] = val;
	}
	
	int T;
	cin >> T;
	while(T--) {
		
	}
}
int main() {
	init();
}
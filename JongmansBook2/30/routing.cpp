#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

const int INF = 987654321;
int main() {
	int V, E, start;
	cin >> V >> E >> start;
	vector<pair<int,double> > adj[V+1];
	double dist[V+1];
	fill(dist, dist+V+1, INF);
	for(int i=0; i<E; ++i){
		int from, to, val;
		cin >> from >> to >> val;
		adj[from].push_back({to,val});
	}
	// pq.first = 정점 위치
	// pq.second = 가중치
	priority_queue<pair<int, int> > pq;
	dist[start] = 0;
	pq.push({start, 0});
	while(!pq.empty()) {
		int here = pq.top().first;
		int cost = pq.top().second;
		
		pq.pop();
		
		for(int i=0; i<adj[here].size(); ++i) {
			int thereVertex = adj[here][i].first;
			int thereVal = adj[here][i].second;
			if(dist[thereVertex] > dist[here] + thereVal) { 
				dist[thereVertex] = dist[here] + thereVal;
				pq.push({thereVertex,-thereVal });
			} 
		}
	}
	
	for(int i=1; i<=V; ++i){
		cout << dist[i] <<  " ";
	}
	
}


#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

const int INF = 987654321;
int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E, start;
	cin >> V >> E >> start;

	vector<pair<int, int> > adj[V+1];
	vector<int> dist(V+1, INF);
	priority_queue<pair<int, int> > pq;

	for(int i=0; i<E; ++i) {
		int from, to, val;
		cin >> from >> to >> val;
		
		adj[from].push_back(make_pair(val,to));
	}
	
	dist[start] = 0;
	pq.push({dist[start], start});
	while(!pq.empty()) {
		int here = pq.top().second;
		pq.pop(); 
		
		for(int i=0; i<adj[here].size(); ++i){
			int there = adj[here][i].second;
			int thereDistVal = adj[here][i].first;
			int nextDistVal = dist[here] + thereDistVal;
			if(dist[there] > dist[here] + thereDistVal ) {
				dist[there] = nextDistVal;
				pq.push(make_pair(-nextDistVal, there));
			}
		}
	}
	
	for(int i=1; i<=V; ++i) {
		if(dist[i] == INF )
			cout << "INF" << '\n';
		else{
			cout << dist[i] << '\n';
		}
	}
}
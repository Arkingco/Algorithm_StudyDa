#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int INF = 987654321;
int main() {
	int V, E, start;
	cin >> V >> E >> start;
	vector<pair<int, int> > adj[V+1];
	vector<int> dist(V+1, INF);
	
	for(int i=0; i<E; ++i) { 
		int from, to, val;
		cin >> from >> to >> val;
		adj[from].push_back({to, val});
	}
	
	dist[start] = 0;
	for(int iter=0; iter<V; ++iter) {
		for(int here=0; here<V; ++here) {
			for(int i=0; i<adj[here].size(); ++i) {
				int next = adj[here][i].first;
				int nextVal = adj[here][i].second;
				
				int nextDistVal = dist[here] + nextVal;
				if(dist[next] > dist[here] + nextVal) {
					dist[next] = nextDistVal;
				}
			}
		}
	}
	
	for(int i=1; i<=V; ++i) cout << dist[i] << " ";
	

}

#include<iostream>
#include<vector>
using namespace std;

const int MAX_V = 400;
const int INF = 987654321;
int V, E;
vector<pair<int, int> > adj[MAX_V];
int prim(vector<pair<int, int> >& selected) {
	
	int ret = 0;
	int u=0;
	vector<int> minWeight(V+1, INF);
	vector<int> parent(V+1, -1);
	vector<bool> added(V+1, false);
	
	minWeight[0] = parent[0] = 0;
	for(int iter = 0; iter < V; ++iter) {
		u = -1;
		for(int v=0; v<V; ++v) {
			if(!added[v] && (u == -1 || minWeight[u] > minWeight[v])) 
			{
				u = v;	
			}
		}
		if(parent[u] != u) selected.push_back({parent[u], u});
		added[u] = true;
		ret += minWeight[u];
		for(int i = 0; i<adj[u].size(); ++i ) {
			int v = adj[u][i].first;
			int weight = adj[u][i].second;
			
			if(!added[v] && minWeight[v] > weight) {
				parent[v] = u;
				minWeight[v] = weight;
			}
		}
	}
	
	return ret;
}
void init() {
	cin >> V >> E;
	
	for(int i=0; i<E; ++i) {
		int from, to, val;
		cin >> from >> to >> val;
		adj[from].push_back({to, val});
		adj[to].push_back({from, to});
	}
	vector<pair<int, int> > getPrim;
	int result = prim(getPrim);
	cout << result << endl;
}
int main() {
	init();
}
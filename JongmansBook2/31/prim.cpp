#include<iostream>
#include<vector>
using namespace std;

const int MAX_V = 400;
const int INF = 987654321;
int V, E;
vector<pair<int, int> > adj[MAX_V];
int prim(vector<pair<int, int> >& selected) {
	
	int ret = 0;
	vector<int> minHeight(V+1, INF);
	vector<int> parent(V+1, INF);
	vector<bool> added(V+1, false);
	
	minHeight[0] = parent[0] = 0;
	for(int iter = 0; iter<V; ++iter) {
		int u = -1;	
		for(int v=0; v<V; ++v) {
			if(!added[v] && (u == -1 || minHeight[u] > minHeight[v])) {
				u = v;
			}
		}
		added[u] = true;
		ret += minHeight[u];
		
		if(parent[u] != u) selected.push_back({parent[u], u});
		
		for(int i=0; i<adj[u].size(); ++i ) {
			int v = adj[u][i].first, vHeight = adj[u][i].second;
			if(!added[v] && (minHeight[v] > vHeight)) {
				minHeight[v] = vHeight;
				parent[v] = u;
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
	for(int i=0; i<getPrim.size(); ++i) {
		cout << getPrim[i].first << " " << getPrim[i].second << endl;
	}
	cout << result << endl;
}
int main() {
	init();
}
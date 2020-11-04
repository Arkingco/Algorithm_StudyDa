#include<iostream>
#include<vector>
using namespace std;


int V, E;
int delay[500];
vector<vector<int> > adj;
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
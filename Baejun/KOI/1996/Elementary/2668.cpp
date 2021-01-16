#include<iostream>
#include<vector>

using namespace std;

vector<int>  adj;

int bfs() {
	return 0;
}

int main() {
	int n;
	cin >> n;
	
	adj = vector<int>(n, 0);
	
	for(int i=0; i<n; ++i) {
		int value;
		cin >> value;
		adj[i].push_back(value);
	}
	
}
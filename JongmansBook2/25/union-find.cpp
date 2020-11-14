#include<iostream>
#include<vector>
using namespace std;

struct OptimizedDisjointSet {
	vector<int> parent, rank;
	OptimizedDisjointSet(int n) : parent(n), rank(n,1) {
		for(int i=0; i<n; ++i) {
			parent[i] = i;
		}
	}
	void swap(int& a, int& b) {
		int swapNumber = a;
		a = b;
		b = swapNumber;
	}
	int find(int u) {
		if(u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}
	void Union(int u, int v) {
		int Ur = find(u);
		int Uv = find(v);
		
		if(Ur == Uv) return;
		
		if(rank[Ur] > rank[Uv]) 
			swap(Ur, Uv);
		
		parent[Ur] = Uv;
		
		if(rank[Ur] == rank[Uv] )
			++rank[Uv];
 		
	}	
};

int main() {
	
}
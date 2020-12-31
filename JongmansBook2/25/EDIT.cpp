#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct BipartiteUnionFind {
	vector<int> parent, rank, enemy, size;
	BipartiteUnionFind(int n) : parent(n), rank(n, 0), enemy(n, -1), size(n, 1)  {
		for(int i=0; i<n; ++i) {
			parent[i] = i;
		}
	}
	
	int find(int u) {
		if(parent[u] == u) return u;
		return parent[u] = find(parent[u]);
	}
	
	int merge(int u, int v) {
		if(u == -1 || v == -1) 
			return max(u, v);
		
		u = find(u); v = find(v);
		
		if(u == v) return u;
		
		if(rank[u] > rank[v]) 
			swap(u, v);
		if(rank[u] == rank[v]) 
			rank[v]++; 
		
		parent[u] = v;	
		size[v] += size[u];
		
		return v;
	}
	
	bool dis(int u, int v) {
		u = find(u); v = find(v);
		if(u == v) return false;
		
		int a = merge(u, enemy[v]); 
		int b = merge(v, enemy[u]);
		
		enemy[a] = b;
		enemy[b] = a;
		return true;
	}
	
	bool ack(int u, int v) {
		u = find(u); v = find(v);
		if(enemy[u] == v || enemy[v] == u) return false;
		
		int a = merge(u, v); int b = merge(enemy[u], enemy[v]);
		
		enemy[a] = b;
		if(enemy[b] != -1) enemy[b] = a;
		
		return true;
	}
	
};

//
int Maxpart(const BipartiteUnionFind& buf, int n) {
	int ret = 0;
	for(int node = 0; node < n; ++node) {
	 	if(buf.parent[node] == node) {
			int enemy = buf.enemy[node];
			cout << enemy << " " << node  << endl;
			// 같은 모인 쌍을 두 번 세지 않기 위해, enemy < node 경우만 샌다.
			// enemy == -1 인 경우도 정확히 한 번씩 세게 한다.
			if(enemy > node) continue;
			cout <<  "in "<< enemy << " " << node << endl;
			int mySize = buf.size[node];
			int enemySize = (enemy == -1 ? 0 : buf.size[enemy]);
			// 두 집합 중 큰 집합을 더한다.
			ret += max(mySize, enemySize);
		}
	}
	return ret;
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n, m;
		cin >> n >> m;
		BipartiteUnionFind* BTUF = new BipartiteUnionFind(n);
		for(int i=0; i<m; ++i) {
			string value;
			int u, v;
			cin >> value >> u >> v;
			
			if(value == "ACK") BTUF->ack(u, v);
			else { 
				BTUF->dis(u, v);
			}
		}
		cout << endl;cout << endl;
		
		for(int i=0; i<n; ++i) {
			cout << BTUF->parent[i] << " ";
		}
		cout << endl;
		for(int i=0; i<n; ++i) {
			cout << BTUF->enemy[i] << " ";
		}
		cout << endl;cout << endl;
		cout << Maxpart(*BTUF, n) << endl;
	}
}

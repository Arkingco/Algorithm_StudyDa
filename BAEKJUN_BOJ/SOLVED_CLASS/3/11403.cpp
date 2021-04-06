#include<iostream>
#include<stdio.h>
using namespace std;

const int INF = 987654321;
const int MAX_V = 103;

int V;
int adj[MAX_V][MAX_V];


void floyd() {
	for (int k = 0; k < V; ++k) {
		for (int i = 0; i < V; ++i) {
			for (int j = 0; j < V; ++j) {
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
}


int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);


	// 간선
	cin >> V;

	for (int i = 0; i < V; ++i) {
		for (int j = 0; j < V; ++j) {
			int value;
			cin >> value;

			if (value == 1) {
				adj[i][j] = 1;
			}
			else {
				adj[i][j] = INF;
			}
		}
	}

	floyd();

	for (int i = 0; i < V; ++i) {
		for (int j = 0; j < V; ++j) {
			if (adj[i][j] == INF) {
				cout << "0 ";
			}
			else {
				cout << "1 ";
			}
		}
		cout << endl;
	}
}

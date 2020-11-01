#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

const int INF = 987654321;
const int MAX_INDEX = 100;

int V,E;

vector<vector<int> > adj; // (Adjacency = 인접)
vector<vector<int> > via;
int C[MAX_INDEX][MAX_INDEX][MAX_INDEX];

void init() {
	
	cin >> V >> E;
	adj = vector<vector<int> >(V+1, vector<int>(V+1, INF));
	via = vector<vector<int> >(V+1, vector<int>(V+1, -1));
	
	for(int i=0; i<E; ++i) {
		int from, to, val;
		cin >> from >> to >> val;
		adj[from][to] = val;
	}
	
}
void printAdj() {
	for(int k=0; k<=V; ++k){
		cout << endl;
		cout << endl;
		for(int i=1; i<=V; ++i) {
			cout << endl;
			for(int j=1; j<=V; ++j) {
				if(adj[i][j] == INF)
					cout << "I" << " ";
				else 
					cout << adj[i][j] << " ";
			}
		}
	}
	
}

void makeFloyd() {
	
	for(int from=1; from<=V; ++from)
		for(int to=1; to<=V; ++to)
			if(from ==to)
				adj[from][to] = 0;
	printAdj();
	
	for(int k=V; k>1; --k)
		for(int from=1; from<=V; ++from){
			for(int to=1; to<=V; ++to){
				adj[from][to] = min(adj[from][to], adj[from][k] + adj[k][to]);
			}
			printAdj();
		}
	// end
}

void makeFloyd2() {
	for(int i=1; i<=V; ++i){
		adj[i][i] = 1;
	}
	for(int k=1; k<=V; ++k)
		for(int i=1; i<=V; ++i)
			for(int j=1; j<=V; ++j)
				if(adj[i][j] > adj[i][k] + adj[k][j]) {
					via[i][j] = k;
					adj[i][j] = adj[i][k] + adj[k][j];
				}
}

void reconstruct(int u, int v, vector<int>& path) {
	// 기저 사례
	// 이부분은 이미 정당성 검증이 끝난 애들을 넣어주는 부분임
	if(via[u][v] == -1) {
	}
	else {
		int w = via[u][v];
		reconstruct(u, w, path);
		path.push_back(w);
	}
}
int main() {
	
	init();
	makeFloyd2();
	vector<int> path;
	reconstruct(1,5,path);
	cout << endl;
	for(int i=0; i<path.size(); ++i)
		cout << path[i] << " " ;
	cout << endl;
	for(int i=1; i<=V; ++i) {
		for(int j=1; j<=V; ++j) {
			cout << via[i][j] << " ";
		}
		cout << endl;
	}
			
}
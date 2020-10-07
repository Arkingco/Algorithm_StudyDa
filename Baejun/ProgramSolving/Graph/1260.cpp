#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N , M , V;
vector<vector<int> >adj;
vector<bool> visited;
void bfs(int here , vector<int>& list){
	queue<int> q;
	q.push(here);
	visited[here] = true;
	list.push_back(here);
	while(!q.empty()){
		int there = q.front();
		q.pop();
		for(int i=0; i<adj[there].size(); ++i){
			int next = adj[there][i];
			if(!visited[next]){
				q.push(next);
				list.push_back(next);
				visited[next] = true;
			}
		}
	}	
}

void dfs(int here , vector<int>& list){
	visited[here] = true;
	list.push_back(here);
	for(int i=0; i<adj[here].size(); ++i){
		int next = adj[here][i];
		if(!visited[next]){
			dfs(next,list);	
		}
	}
}

// 정점 간선 시작점
int main(){
	
	cin >> N >> M >> V;
	adj = vector<vector<int> >(N+1 , vector<int>(0,0));
	visited = vector<bool> (N+1 , false);
	
	for(int i=0; i<M; ++i){
		int a , b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i=1; i<=N; ++i){
		sort(adj[i].begin(), adj[i].end());
	}
	vector<int> list;
	
	dfs(V , list);
	for(int i=0; i<list.size(); ++i)
		cout << list[i] << " ";
	
	visited = vector<bool> (N + 1 , false);
	list = vector<int> (0 ,0);
	cout << endl;
	
	bfs(V , list);
	for(int i=0; i<list.size(); ++i)
		cout << list[i] << " ";
}

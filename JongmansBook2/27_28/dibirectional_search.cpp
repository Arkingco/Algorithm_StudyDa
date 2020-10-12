#include<iostream>
#include<map>
#include<queue>
#include<vector>
using namespace std;

class Graphs{
	vector<vector<int> > adj;
	vector<int> visited_start_From_left;
	vector<int> visited_start_From_right;
}
int V , E;
void BFS(int here){
	queue<int> q;
	q.push(here);
	visited[here] = true;
	while(!q.empty()){
		int next = q.front();
		q.pop();
		cout << next << " ";
		for(int i=0; i<adj[next].size(); ++i){
			int there = adj[next][i];
			if(!visited[there]){
				q.push(there);
				visited[there] = true;
			}
		}
	}
}
/*
13 12
1 2
1 3
1 4
4 5
4 7
4 6
12 11
12 13
12 8
8 9
8 10
8 6
*/	
int main(){
	cin >> V >> E;
	adj = vector<vector<int > >(V+1 , vector<int>(0,0));
	visited = vector<bool>(V+1 , false);
	for(int i=0; i<E; ++i){
		int a , b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	BFS(1);
}










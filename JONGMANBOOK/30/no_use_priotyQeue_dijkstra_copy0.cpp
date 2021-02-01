#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<vector<pair<int,int> > > adj;
vector<bool> visited;
vector<int> dist;
const int INF = 987654321;
int V , E, start;

// 우선순위큐에 넣는 이유가 뭐지?
// 우선순위큐는 데이터를 넣을때 가장 큰 값이 제일 앞으로 가고 자식 노드가 2개로 생긴다는 특징이 있다.
// 그리고 일반 큐로 넣을때는 너비우선 탐색방식으로 값이; 결정되기 때문에 정확한 최소점을 찾을수 없는 특징도 있다
// 그래서 우선순위 큐를 사용해서 너비우선 탐색 방식이지만 가장 작은 값 먼저 들어갈 수 있게 하는 것이 특징이다.

void bfs(int start){
	dist[start] = 0; visited[start] = false;
	while(true) {
		// 아직 방문하지 않은 정점 중 가장 가꾸운 정점을 찾는다.
		int closest = INF, here;
		for(int i=1; i<=V; ++i) {
			// 
			if( !visited[i] && dist[i] < closest) {
				here = i;
				closest = dist[i];
			}
		}
		
		// 모든 정점을 방문했을 때
		if(closest == INF) break;
		
		// 가장 가까운 정점을 방문한다.
		visited[here] = true;
		for(int i=0; i< adj[here].size(); ++i) {
			int there = adj[here][i].second;
			if(visited[there]) continue;
			int nextDist = dist[here] + adj[here][i].first;
			dist[there] = min(nextDist, dist[there]);
		}
	}
	
	return;
}

void show() {
	for(int i=1; i<=V; ++i)
		cout << dist[i] << " ";
}

void init(){
	adj = vector<vector<pair<int,int> > >(V+1, vector<pair<int, int> > (0 , {0,0}));
	visited = vector<bool>(V+1, false);
	dist = vector<int>(V+1, INF);
}


void input(){
	cin >> V >> E >> start;
	init();
	for(int i=0; i<E; ++i){
		int from, to, val;
		cin >> from >> val >> to;
		adj[from].push_back({val, to});
	}
	bfs(start);
	show();
}



int main(){
	input();
}
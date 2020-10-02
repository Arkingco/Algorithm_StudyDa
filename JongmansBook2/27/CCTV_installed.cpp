#include<iostream>
#include<vector>
using namespace std;


// 이 문제에서 중요한 건 그래프를 루트 없는 트리로 변환하면 좀 더 문제를 쉽게 풀 수
// 있는 방식이 나온다는 얘기이다. 
// 루트 없는 트리의 속성은 다음 3가지 중 하나라도 성립하면 된다(3가지가 동치)
// 	1. 정확히 V-1의 간선이 있다.
// 	2. 사이클이 존재하지 않는다.
// 	3. 두 정점 사이를 연결하는 단순 경로가 정확히 하나 있다.
// 이 조건이 성립하면 루트 없는 트리가 성립한다.
// 이 문제를 해결하는 방법은 다음과 같다.
// 그래프를 루트 없는 트리로 변경하여 트리 형태로 문제로 바꾸고 
// 트리 지배 집합을 찾는 것
// DFS 탐색을 이용해서 재귀의 끝까지 간다.
// 그 이후 다음 조건은 다음과 같다.

// 	1. 잎 노드는 선택하지 않는다.
//	2. 이 외의 노드에 대해, 트리의 맨 밑에서부터 올라오면서 다음과 같은 작업을 수행한다.
// 		a) 자기 자손 중 아직 지배당하지 않은 노드가 있다면 현재 노드를 선택합니다.
//		b) 나머지 경우에는 전부 예외처리 합니다.
vector<vector<int > > adj;
vector<bool> visited;
int V , E;
const int UNWATCHED = 0;
const int WATCHED = 1;
const int INSTALLED = 2;
int installed = 0;
int dfs(int here){
	visited[here] = true;
	int children[3] = {0 , 0 , 0};
	for(int i=0; i<adj[here].size(); ++i){
		int there = adj[here][i];
		
		if(!visited[there]){
			++children[dfs(there)];
		}
	}
	
	if(children[UNWATCHED]){
		++installed;
		return INSTALLED;
	}
	if(children[INSTALLED])
		return WATCHED;
	return UNWATCHED;
}
// 그래프를 감시하는 데 필요한 카메라의 최소 수를 반환한다.
int installCamera(){
	installed = 0;
	for(int i=0; i<V; ++i){
		if(!visited[i] && dfs(i) == UNWATCHED)
			++installed;
	}
	return installed;
}

int main(){
	cin >> V >> E;
	adj = vector< vector<int>>(V+1 , vector<int>(0,0));
	visited = vector<bool> ( V+1 , false);
	for(int i=0; i<E; ++i){
		int a , b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int result = installCamera();
	cout << result << '\n';
}










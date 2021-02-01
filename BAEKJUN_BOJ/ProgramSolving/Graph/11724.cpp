#include <iostream>
#include <vector>
using namespace std;
int  V , E;
vector<bool> visited;
vector<vector<int> > graph;
void dfs(int here){
	visited[here] = true;
	for(int i=0; i<graph[here].size(); ++i){
		int there = graph[here][i];
		if(!visited[there])
			dfs(there);
	}
}
int main(){
    cin >> V >> E;
	graph = vector<vector<int> >(V+1 , vector<int>(0 , 0));
	visited = vector<bool>(V+1 , false);
    for(int i =1; i<=E; i++){	
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
	int componentCount = 0;
	// 입력의 방식에 따라 1부터 할지 0부터 할지 정하는게 국룰
    for(int i=1; i<=V; ++i){
		if(!visited[i]) {
			componentCount++;
			dfs(i);
		}
	}
	cout << componentCount << '\n';     
    return 0;
}
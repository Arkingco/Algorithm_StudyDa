#include <iostream>
#include <vector>
using namespace std;
int  V , E;
vector<bool> visited;
vector<vector<int> > graph;
int counet = 0;
void dfs(int here){
	visited[here] = true;
	counet++;
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
    dfs(1);
	cout << counet-1 << '\n';     
    return 0;
}
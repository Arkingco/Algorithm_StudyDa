#include<iostream>
#include<vector>
using namespace std;

void matrix_dfs (int x){
	check[x] = true;
	cout << x << endl;
	for(int i=1; i<=n; ++i){
		if( a[x][i] == 1 && check[i] == false)
			dfs[i];
	}
}
void list_dfs(int x){
	check[x] = true;
	printf("%d ",x);
	for(int i=0; i<a[x].size(); ++i){
		int y = a[x][i];
		if( check[y] == false ){
			dfs(y);
		} 
	}
}
int main(){
	int n,m;
	cin >> n >> m;
	
	vector<int> graph[n+1];
	
	for(int i=0; i<m; ++i){
		int u,v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u)
		// 단방향의 경우 graph[u].push_back(v);만 작성
        // 가중치가 있는 경우 vector<pair<int,int>> graph[n+1];로 만들거나 구조체를 만들어서 가중치와 함께 저장
        // graph[u].push_back(make_pair(v,w)); u->v 가중치: w
 
	}
}
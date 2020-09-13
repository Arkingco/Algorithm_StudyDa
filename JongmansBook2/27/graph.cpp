#include<iostream>
using namespace std;

// 행렬을 이용한 구현
int main(){
	int n,m;
	cin >> n >> m;
	int graph[n+1][n+1];
	
	// 정적으로 선언했기 때문에 값들을 전부 -1로 초기화
	for(int i=0; i<=n; ++i){
		for(int j=0; j<=n; ++j){
			graph[i][j]= -1;
		}
	}
	
	for(int i=0; i<m; ++i){
		int u,v;
		scanf("%d %d" , &u , &v);
		graph[u][v] = graph[v][u] = 1;
	}
}
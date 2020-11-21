#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int N, M;
vector<int> Xboard;
vector<int> Yboard;
// 이미 추가된 간선 
vector<bool> added(N+1, false);
vector<vector<double> > adj(N+1, vector<double>(N+1, 0.0));

// 두 점 사이의 거리를 구하는 함수
double Distance_between_two_points(int x1, int y1, int x2, int y2) {
	
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// 이미 연결되어있는 added를 뺀 나머지 정점들의 최단 스패닝 트리 의 합
int prim() {
	for(int i=0; i<N; ++i) {
		if(added[i]) {
			for(int i=0; i<N; ++i) {
				
			}
				
		}
	}
	int ret =0;
	for(int iter = 0; iter<N; ++iter) {
		int u = -1;
		for(int v=0; v<N; ++v) {
			if(!added[i])
		}
	}
		
}
int board[1000][1000];
int main() {
	int T;
	cin >> T;
	
	while(T--){
		cin >> N >> M;
		

		
		for(int i=0; i<N; ++i) {
			int x;
			cin >> x;

			Xboard.push_back(x);
		}
		for(int i=0; i<N; ++i) {
			int y;
			cin >> y;
			
			Yboard.push_back(y);
		}
		for(int i=0; i<M; ++i) {
			int alreadyConnect;
			cin >> alreadyConnect;
			
			added[alreadyConnect] = true;
		}
		
		for(int i=0; i<N; ++i) {
			for(int j=0; j<N; ++j) {
				if(i != j){
					adj[i][j] = Distance_between_two_points(Xboard[i], Yboard[i], Xboard[j], Yboard[j]);
				}
			}
		}
		
	}
	
}

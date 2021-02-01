#include<iostream>
using namespace std;

const int MAX_N = 100000;
int n;
vector<int> child[MAX_N];
// 트리의 번호와 일령 번호 사이의 대응 관계
int no2serial[MAX_N], serial2no[MAX_N];

// 각 노드가 trip에 처음 당장하는 위치, 그리고 각 노드의 깊이
int locInTrip[MAX_N], depth[MAX_N];

// 다음 일련번호
int nextSerial;
// 깊이가 d인 노드 here 이하를 전위 탐색한다.
void traverse(int here, int d, vector<int>& trip) {
	// traverse() 가 처음 방문하자마자 일련 번호를 부여한다.
	no2serial[here] = nextSerial;
	serial2no[nextSerial] = here;
	++nextSerial;
	depth[here] = d;
	// trip에 현재 노드의 일련번호를 추가한다.
	locInTrip[here] = trip.size();
	trip.push_back(no2serial[here]);
	// 모든 자식 노드를 방문
	for(int i=0; i<child[here].size(); ++i) {
		traverse(child[here][i], d+1, trip);
		// 자식 노드를 방문하고 현재 노드로 돌아올 때마다 다시 추가하기
		trip.push_back(no2serial);
		
	}
}
int main(){
	
}
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;

int C , n;
// perm을 정렬하기 위해 필요한 최소 뒤집기 연산의 수를 계산한다.
int bfs(const vector<int>& perm){
	int n = perm.size();
	// 목표 정점을 미리 계산한다.
	vector<int> sorted = perm;
	sort(sorted.begin() , sorted.end());
	// 방문 목록(큐)과 시작점부터 각 정점까지의 거리
	queue<vector<int> >q;
	map<vector<int> , int> distance;
	// 시작점을 큐에 넣는다.
	distance[perm ] = 0;
	q.push(perm);
	while(!q.empty()){
		vector<int> here = q.front();
		q.pop();
		// 목표 정점을 발견했으면 곧장 종료한다.
		if(here == sorted ) return distance[here];
		int cost = distance[here];
		// 가능한 모둔 부분 구간을 뒤집어 본다.
		for(int i=0; i<n; ++i)
			for(int j= i + 2; j <= n; ++j){
				reverse(here.begin() + i , here.begin() + j);
				if(distance.count(here) == 0){
					distance[here] = cost + 1;
					q.push(here);
				}
				reverse(here.begin() + i , here.begin() + j);
			}
	}
	return 1;
}
int main(){
	cin >> C;
	while(C--){
		cin >> n;
		vector<int> list(n,0);
		for(int i=0; i<n; ++i)
			cin >> list[i];
		
		cout << bfs(list) << endl;
	}
}


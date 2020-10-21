#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

/* 
	문제: 철인 N종 경기
	
	첫 번째 줄에는 테스트 케이스의 수 			  : C
	각 테스트 케이스의 첫 줄에는 체택 가능한 종목의 수 : M
3
2 1
7 3
5
1 100
20 11
21 20
10 1
2 101
3
10 81
63 71
16 51
*/

// 정점의 개수
int V;
int C, M;

// 그래프의 인접 리스트. (연결된 정점 번호, 간선 가중치)쌍을 담는다.
vector<pair<int, int> > adj[410];

const int START = 401;
const int INF = 987654321;
const int MAX_ABS = 200;
const int MIN_ABS = -200;


vector<int> dijkstra(int start) {
	
	priority_queue<pair<int, int> > pq;
	vector<int> dist(410, INF);
	
	dist[start] = 0;
	pq.push({dist[start], start});
	
	while(!pq.empty()) {
		int here = pq.top().second;
		
		for(int i=0; i<adj[here].size(); ++i) {
			int next = pq.top().second;
			int nextVal = pq.top().first;
			
			pq.pop();
			
			int nextDistValue = dist[here] + nextVal;
			if(dist[next] > nextDistValue) {
				dist[next] = nextDistValue;
				pq.push({-nextDistValue, next});
			}
		}
	}
	
	return dist;	
}

// (A국 선수의 예상 시간-B국 선수의 예상 시간)의 정점 번호를 반환한다.
int vertex(int delta) {
	return delta + 200;
}

// a[] = A국 선수의 종목별 예상 시간
// b[] = B국 선수의 종목별 예상 시간
int solve(const vector<int>& a, const vector<int>& b) {
	// 그래프를 만든다.
	V = 402;
	for(int i=0; i<V; ++i) adj[i].clear();
	for(int i=0; i<a.size(); ++i) {
		int delta = a[i] - b[i];
		adj[START].push_back({vertex(delta), a[i]});
	}
	// 현재 차이
	for(int delta = -MIN_ABS; delta <= MAX_ABS; ++delta) {
		// i번 종목을 뒤에 더 붙인다면?
		for(int i=0; i<a.size(); ++i) {
			int next = delta + a[i] - b[i];
			// 시간 차이의 절대 값이 200을 넘는 정점을 만들 필요가 없다.
			if(abs(next) > MAX_ABS) continue;
			adj[vertex(delta)].push_back({vertex(next), a[i]});
		}
	}
	
	vector<int> shortest = dijkstra(START);
	int ret = shortest[vertex(0)];
	if(ret == INF) return -1;
	return ret;
}


int main() {
	cin >> C;
	while(C--) {
		cin >> M;
		vector<int> a, b;
		
		for(int i=0; i<M; ++i) {
			int input_a, input_b;
			cin >> input_a >> input_b;
			a.push_back(input_a);
			b.push_back(input_b);
		}
		
		int ProgramResult = solve(a, b);
		
		cout << ProgramResult << endl;
	}
}

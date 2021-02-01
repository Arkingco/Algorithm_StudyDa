#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int V , E;
vector<vector<int > > adj;

vector<pair<int,vector<int>>> sort_list;
// 각 정점의 컴포넌트 번호는 0부터 시작하며
// 같은 강결합 컴포넌트에 석한 정점들의 컴포넌트 번호가 같다.
vector<int> sccId;
// 각 정점의 발견 순서
vector<int> discovered;
stack<int> st;
int sccCounter , vertexCounter;
// here를 루트로 하는 서브트리에서 역방향 간선이나 교차 간선을 
// 통해 갈 수 있는 정점 중 최소 발견 순서를 반환한다.
// (이미 SCC로 묶인 정점으로 연결된 교차 간선은 무시한다.)
int scc(int here){
	int ret = discovered[here] = vertexCounter++;
	// 스택에 here를 넣는다. here의 후손들은 모두 스택에서 here 후에 들어간다.
	st.push(here);
	for(int i=0; i<adj[here].size(); ++i){
		int there = adj[here][i];
		// (here , there) 가 트리간선
		if(discovered[there] == -1)
			ret = min(ret , scc(there));
		// there 가 무시해야 하는 교차 간선이 아니라면
		else if(sccId[there] == -1)
			ret = min(ret , discovered[there]);
	}
	// 여기가 좀 중요함
	// here에서 부모로 올라가는 간선을 끊어야 할지 확인한다.
	if ( ret == discovered[here]){
		// here를 루트로 하는 서브트리에 남아 있는 정점들을 전부 하나의 컴포넌트로 묶는다.
		while(true) {
			int t = st.top();
			st.pop();
			sccId[t] = sccCounter;
			if(t == here) break;
		}
		++sccCounter;
	}
	return ret;
}
// tarjan의 SCCdkfrhflwma
vector<int> tarjanSCC(){
	// 배열들을 전부 초기화
	sccId = discovered = vector<int>(adj.size()+1 , -1);
	// 카운터 초기화
	sccCounter = vertexCounter = 1;
	// 모든 정점에 대해 scc()호출
	for(int i=1; i<adj.size(); ++i) if(discovered[i] == -1) scc(i);
	return sccId;
}
int main(){
	cin >> V >> E;
	adj = vector<vector<int> >(V+1, vector<int>(0,0));
	sort_list = vector<pair<int , vector<int>>>(V , V , vector<int>(0,0));
	for(int i=0; i<E; ++i){
		int a , b;
		cin >> a >> b;
		adj[a].push_back(b);
	}
	vector<int> list = tarjanSCC();
	
	for(int i=1; i<=V; ++i){
		for(int j=1; j<=V; ++j){
			if(i == list[j]){
			sort_list
			}
		}
		
	}
}
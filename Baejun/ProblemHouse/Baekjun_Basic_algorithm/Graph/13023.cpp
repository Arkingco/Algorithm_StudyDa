#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > adj_semi;
vector<vector<int> > adj;
vector<bool> visited;
int count = 0;
int n, m;
void set(){
	visited = vector<bool>(n , 0);
	adj_semi = adj;
}
void getEulerCircuit(int here , vector<int>& circuit){
	visited[here] = 1;
	for(int there = 0; there < adj_semi[here].size(); ++there){
		int next = adj[here][there];
		if(visited[next]) continue;
		getEulerCircuit(next , circuit);
	}
	visited[here] = false;
	circuit.push_back(here);
}
int main(){
	// 사람수 >> 친구 관계수
	cin >> n >> m;
	adj = vector<vector<int> >( n , vector<int>( 0 , 0 ));
	
	for(int i=0; i<m; ++i){
		int a , b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	
	for(int i=0; i<n; ++i){
		vector<int> list;
		set();
		getEulerCircuit(i , list);
		
		for(int show = 0; show<list.size(); ++show){
			cout << list[show] << " " ;
		}
		
		cout << endl;
	}
	// for(int i=0; i<n; ++i){
	// 	if(visited[i] == 0)
	// 		makeGraph(i);
	// }
}




/*
8 8
1 7
3 7
4 7
3 4
4 6
3 5
0 4
2 7
*/






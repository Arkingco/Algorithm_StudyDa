#include<iostream>
#include<stack>
#include<vector>
using namespace std;

const int MAX_SIZE = 10;
int n,m;
vector<int> grape[MAX_SIZE];
bool visited[MAX_SIZE];
stack<int> stackey;
void dfs(int v){
	for(int i=0; i<grape[v].size(); ++i){
		int next = grape[v][i];
		if(visited[next] == false){
			visited[next] = true;
			dfs(next);
		}
	}
	stackey.push(v);
}

int main(){
	
	cin >> n >> m;
	
	
	for(int i=0; i<m; ++i){
		int a,b;
		cin >> a >> b;
		
		grape[a].push_back(b);
	}
	for(int i=1; i<=n; ++i){
		if(visited[i] == false) {
        	visited[i] = true;
        	dfs(i);
        }
	}
	
	while(!stackey.empty()){
		cout << stackey.top() << " ";
		stackey.pop();
	}
}

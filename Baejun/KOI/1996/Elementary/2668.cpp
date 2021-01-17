#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> adj;
vector<int> visit;
vector<int> check;
void bfs(int here, vector<int>& result) {
	
	check[here]++;
	visit[here]++;
	int next = adj[here];
	if(visit[here] > 2) return;
	if(check[here] == 2) result.push_back(here);
	if(check[next] < 2) bfs(next, result);
	
}

int main() {
	int n;
	cin >> n;
	
	
	adj.push_back(0);
	for(int i=0; i<n; ++i) {
		int value;
		cin >> value;
		
		adj.push_back(value);
	}
	
	
	vector<int> result;
	visit = vector<int>(n+1, 0);
	for(int i=1; i<=n; ++i) {
		vector<int> ret;
		check = vector<int>(n+1, 0);
		
		bfs(i, ret);
		
		for(int i=0; i<ret.size(); ++i) {
			result.push_back(ret[i]);
		}
	}
	
	sort(result.begin(), result.end());
	cout << result.size() << '\n';
	for(int i=0; i<result.size(); ++i) {
		cout << result[i] << '\n';
	}
}
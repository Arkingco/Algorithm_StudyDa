#include<algorithm>
#include<string.h>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
using namespace std;

vector<vector<int>> adj;
bool visited[53];
bool fact[53];
bool check = false;

void dfs(int here) {

	if (fact[here]) {
		check = true;
		return;
	}

	visited[here] = true;
	
	for (int i = 0; i < adj[here].size(); ++i) {
		int next = adj[here][i];
		if (!visited[next]) {
			dfs(next);
		}
	}

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, know;
	cin >> n >> m >> know;

	memset(fact, false, sizeof fact);
	
	for (int i = 0; i < know; ++i) {
		int value;
		cin >> value;

		fact[value] = true;
	}
	
	vector<vector<int>> member = vector <vector<int>>(m, vector<int>(0, 0));
	adj = vector<vector<int>>(n+1, vector<int>(0, 0));
	for (int i = 0; i < m; ++i) {
		int party_n;
		cin >> party_n;

		bool check = false;

		for (int j = 0; j < party_n; ++j) {
			int value;
			cin >> value;

			member[i].push_back(value);
		}

		for (int j = 0; j < member[i].size(); ++j) {
			for (int z = 0; z < member[i].size(); ++z) {
				if (j != z) {
					adj[member[i][j]].push_back(member[i][z]);
				}
			}
		}

	}

	int result = 0;
	for (int i = 0; i < m; ++i) {

		check = false;
		for (int j = 0; j < member[i].size(); ++j) {
			memset(visited, false, sizeof visited);
			dfs(member[i][j]);
			if (check == true) {
				break;
			}
		}

		if (!check) {
			result++;
		}

	}

	cout << result << '\n';
}
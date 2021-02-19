#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
#include<math.h>
#include<stack>
#include<queue>
#include<stdio.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	int root[15][15];
	memset(root, 0, sizeof root);
	
	for (int j = 0; j < 15; ++j) {
		root[0][j] = j;
	}
	for (int i = 1; i < 15; ++i) {
		for (int j = 1; j < 15; ++j) {
			root[i][j] = root[i - 1][j] + root[i][j - 1];	
		}
	}

	while (t--) {
		int n, m;
		cin >> n >> m;
		cout << root[n][m] << '\n';
	}
}

#include<algorithm>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
using namespace std;

typedef pair<int, int> pii;

int visited[101][101] = { false };
int boardY[4] = { -1, 0, 0, 1 };
int boardX[4] = { 0, -1, 1, 0 };
int dp[101][101] = { 0 };
int board[101][101];
int n, m;

bool check(int y, int x) {
	if (y < 0 || y > n - 1 || x < 0 || x > m - 1) return false;

	return true;
}
int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		string value;
		cin >> value;
		
		for (int j = 0; j < m; ++j) {
			board[i][j] = (int)value[j]-48;
		}
	}

	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	visited[0][0] = true;
	dp[0][0] = 1;

	while (!q.empty()) {
		pii front = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {

			int nexty = front.first + boardY[i];
			int nextx = front.second + boardX[i];

			if (!check(nexty, nextx)) continue;

			if (board[nexty][nextx] == 1 && visited[nexty][nextx] == false) {
				dp[nexty][nextx] = dp[front.first][front.second] + 1;
				visited[nexty][nextx] = true;

				q.push({ nexty, nextx });	
			}
			
		}
	}
	
	cout << dp[n-1][m-1] << endl;
}

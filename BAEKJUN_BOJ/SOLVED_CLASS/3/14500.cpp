#include<algorithm>
#include<iostream>
#include<vector>
#include<cstring>
#include<string.h>

using namespace std;

bool visited[503][503];
int board[503][503];
int resultMax = 0;
int n, m;

void polyAnother(int y, int x) {

	if (y - 1 >= 0 || x - 1 >= 0 || x + 1 < m -1) {
		resultMax = max(resultMax, board[y][x] + board[y - 1][x] + board[y][x - 1] + board[y][x + 1]);
	}

	if (y + 1 < n - 1 || x - 1 >= 0 || x + 1 < m - 1) {
		resultMax = max(resultMax, board[y][x] + board[y + 1][x] + board[y][x - 1] + board[y][x + 1]);
	}

	if (y - 1 >= 0 || y + 1 < n - 1 || x - 1 >= 0) {
		resultMax = max(resultMax, board[y + 1][x] + board[y - 1][x] + board[y][x] + board[y][x - 1]);
	}

	if (y - 1 >= 0 || y + 1 < n - 1 || x + 1 < m - 1) {
		resultMax = max(resultMax, board[y + 1][x] + board[y - 1][x] + board[y][x] + board[y][x + 1]);
	}

}

int yy[4] = { 1, 0, -1, 0 };
int xx[4] = { 0, -1, 0, 1 };
void poly(int y, int x, int size, int sum) {

	if (y < 0 || y > n - 1 || x < 0 || x > m - 1) {
		return;
	}

	sum = sum + board[y][x];
	if (size == 4) {
		resultMax = max(resultMax, sum);
		return;
	}
	
	for (int i = 0; i < 4; ++i) {
		if (visited[y + yy[i]][x + xx[i]]) {
			continue;
		}
		visited[y + yy[i]][x + xx[i]] = true;
		poly(y + yy[i], x + xx[i], size + 1, sum);
		visited[y + yy[i]][x + xx[i]] = false;
	}

}

int main() { 

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	memset(board, 0, sizeof board);
	memset(visited, false, sizeof visited);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			visited[i][j] = true;
			poly(i, j, 1, 0);
			polyAnother(i, j);
			visited[i][j] = false;
		}
	}

	cout << resultMax << endl;
}

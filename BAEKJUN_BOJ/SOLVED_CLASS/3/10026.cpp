#include<algorithm>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<deque>
#include<map>
#include<stack>
using namespace std;


const int R = 17;
const int G = 6;
const int B = 1;

int visited[101][101];
int board[101][101];
int yx[2][4] = {
	{-1, 0, 0, 1} ,
	{0, -1, 1, 0}
};
int n;

int dfs(int hereY, int hereX, int hereRGB, bool check) {
	visited[hereY][hereX] = true;
	
	for (int i = 0; i < 4; ++i) {
		int y = hereY + yx[0][i];
		int x = hereX + yx[1][i];

		if ((y < 0 || y > n || x < 0 || x > n) || visited[y][x]) {
			continue;
		}
		
		// 적녹색약 이라면
		if (check) {
			if (board[y][x] == hereRGB || (hereRGB == R && board[y][x] == G) || (hereRGB == G && board[y][x] == R)) {
				dfs(y, x, hereRGB, true);
			}
		}
		else {
			if (board[y][x] == hereRGB) {
				dfs(y, x, hereRGB, false);
			}
		}
	}

	return 1;
}

int main() {

	
	cin >> n;

	memset(board, 0, sizeof board);
	memset(visited, false, sizeof visited);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			char RGB;
			cin >> RGB;
			board[i][j] = RGB - 'A';
		}
	}

	int result1 = 0;
	int result2 = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!visited[i][j]) {
				result1 = result1 + dfs(i, j, board[i][j], false);
			}
		}
	}

	memset(visited, false, sizeof visited);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!visited[i][j]) {
				result2 = result2 + dfs(i, j, board[i][j], true);
			}
		}
	}

	cout << result1 << " " << result2 << endl;
}
#include<algorithm>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<deque>
#include<map>
using namespace std;

typedef pair<int, pair<int, int>> pipii;

int M, H, N;
int z[6] = { 1, -1, 0, 0, 0, 0 };
int y[6] = { 0, 0, 0, 0, 1, -1 };
int x[6] = { 0, 0, 1, -1 ,0 ,0 };
int board[101][101][101];
int dp[101][101][101];
int count0 = 0;
int count1 = 0;

bool check(int checkZ, int checkY, int checkX) {
	if (checkZ < 0 || checkZ >= H || checkY < 0 || checkY >= N || checkX < 0 || checkX >= M) return false;
	return true;
}

int main() {


	cin >> M >> N >> H;
	queue<pipii> q;

	for (int height = 0; height < H; ++height) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				int value;
				cin >> value;
				board[height][i][j] = value;
				if (value == 0) count0++;
				if (value == -1) count1++;
				if (value == 1) q.push({ height, {i, j} });
			}
		}
	}
	if (count1 == M * N * H) {
		cout << "-1" << endl;
		return 0;
	}
	if (count0 == 0) {
		cout << "0" << endl;
		return 0;
	}

	int result = 0;
	while (!q.empty()) {
		pipii front = q.front();
		q.pop();

		for (int i = 0; i < 6; ++i) {
			int hereZ = front.first;
			int hereY = front.second.first;
			int hereX = front.second.second;

			int Z = z[i] + hereZ;
			int Y = y[i] + hereY;
			int X = x[i] + hereX;

			if (check(Z, Y, X)) {
				if (board[Z][Y][X] == 0) {
					board[Z][Y][X] = 1;
					count0--;
					q.push({ Z, {Y,X} });

					dp[Z][Y][X] = dp[hereZ][hereY][hereX] + 1;
					result = max(result, dp[Z][Y][X]);
				}
			}
		}

	}
	if (count0 > 0) {
		cout << "-1" << endl;
		return 0;
	}
	else {
		cout << result << endl;
		return 0;
	}
}
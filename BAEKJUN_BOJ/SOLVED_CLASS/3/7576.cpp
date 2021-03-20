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

typedef pair<int, int> pii;

int M, N;
int y[4] = { 0, 0, 1, -1 };
int x[4] = { 1, -1 ,0 ,0 };
int board[1001][1001];
int dp[1001][1001];
int count0 = 0;
int count1 = 0;

bool check(int checkY, int checkX) {
	if (checkY < 0 || checkY >= N || checkX < 0 || checkX >= M) return false;
	return true;
}

int main() {


	cin >> M >> N;
	queue<pii> q;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int value;
			cin >> value;
			board[i][j] = value;
			if (value == 0) count0++;
			if (value == -1) count1++;
			if (value == 1) q.push({ i, j });
		}
	}
	
	if (count1 == M * N) {
		cout << "-1" << endl;
		return 0;
	}
	if (count0 == 0) {
		cout << "0" << endl;
		return 0;
	}

	int result = 0;
	while (!q.empty()) {
		pii front = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int hereY = front.first;
			int hereX = front.second;

			int Y = y[i] + hereY;
			int X = x[i] + hereX;

			if (check(Y, X)) {
				if (board[Y][X] == 0) {
					board[Y][X] = 1;
					count0--;
					q.push({ Y,X });

					dp[Y][X] = dp[hereY][hereX] + 1;
					result = max(result, dp[Y][X]);
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
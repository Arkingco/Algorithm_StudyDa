#include<algorithm>
#include<iostream>
#include<vector>
#include<cstring>
#include<string.h>
#include<cmath>
#include<queue>
using namespace std;

typedef pair<int, pair<int, int>> pipii;

pipii shark;
vector<vector<bool>> visited;
vector<vector<int>> boardDistance;

int board[21][21];
int gogiLev = 0;
int result = 0;
int n;

int goY[4] = { 0, 1, 0, -1 };
int goX[4] = { -1, 0, 1, 0 };
vector<pipii> updateGogis() {

	visited = vector<vector<bool>>(n + 1, vector<bool>(n + 1, false));
	boardDistance = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));

	vector<pipii> gogisgogis;

	queue<pipii> q;
	q.push(shark);

	visited[shark.second.first][shark.second.second] = true;
	boardDistance[shark.second.first][shark.second.second] = 0;
	while (!q.empty()) {
		pipii here = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nextY = here.second.first + goY[i];
			int nextX = here.second.second + goX[i];

			if (nextY < 0 || nextY > n - 1 || nextX < 0 || nextX > n - 1) {
				continue;
			}

			if (!visited[nextY][nextX] && board[nextY][nextX] <= shark.first) {
				visited[nextY][nextX] = true;
				boardDistance[nextY][nextX] = boardDistance[here.second.first][here.second.second] + 1;

				q.push({ 0,{nextY, nextX} });
				if (board[nextY][nextX] != 0 && shark.first > board[nextY][nextX]) {
					gogisgogis.push_back({ boardDistance[nextY][nextX], { nextY, nextX } });
				}
			}

		}
	}

	sort(gogisgogis.begin(), gogisgogis.end());

	return gogisgogis;
}

void play() {
	vector<pipii> getGogiList;
	getGogiList = updateGogis();

	if (getGogiList.size() == 0) {
		return;
	}
	else {

		gogiLev++;
		if ((shark.first - gogiLev) == 0) {
			gogiLev = 0;
			shark.first++;
		}
		shark.second.first = getGogiList[0].second.first;
		shark.second.second = getGogiList[0].second.second;
		board[getGogiList[0].second.first][getGogiList[0].second.second] = 0;

		result = result + boardDistance[getGogiList[0].second.first][getGogiList[0].second.second];
		play();
	}
}

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;


	memset(board, 0, sizeof board);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];

			if (board[i][j] == 9) {
				board[i][j] = 0;
				shark = { 2, {i, j} };
			}
		}
	}

	play();

	cout << result << endl;
}

#include<algorithm>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
using namespace std;

const int maxBoardSize = 129;
int board[maxBoardSize][maxBoardSize];
int white = 0;
int blue = 0;

bool check(int y, int x, int size) {
	int firstValue = board[y][x];

	for (int i = y; i < y + size; ++i) {
		for (int j = x; j < x + size; ++j) {
			if (firstValue != board[i][j]) return false;
		}
	}

	return true;
}

void playBoard(int y, int x, int size) {

	if (size == 1) {
		if (board[y][x] == 1) {
			blue++;
		}
		else {
			white++;
		}

		return;
	}

	if (check(y, x, size)) {
		if (board[y][x] == 1) {
			blue++;
		}
		else {
			white++;
		}

		return;
	}
	else {
		int boardSize = size / 2;

		playBoard(y, x, boardSize);
		playBoard(y, x + boardSize, boardSize);
		playBoard(y + boardSize, x, boardSize);
		playBoard(y + boardSize, x + boardSize, boardSize);
	}
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
		}
	}

	playBoard(0, 0, n);

	cout << white << endl << blue << endl;

}

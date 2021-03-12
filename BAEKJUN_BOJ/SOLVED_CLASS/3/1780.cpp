#include<algorithm>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
using namespace std;

const int maxSize = 2188;
int board[maxSize][maxSize] = { 0 };
int result[3] = { 0 };

bool check(int y, int x, int size) {
	int sum = board[y][x];

	for (int i = y; i < size+y; ++i) {
		for (int j = x; j < size+x; ++j) {
			if (sum != board[i][j]) {
				return false;
			}
		}
	}

	result[sum+1]++;

	return true;
}

void sliceBoard(int y, int x, int size) {

	if (size == 1) {
		result[board[y][x] + 1]++;
		return;
	}

	if (!check(y, x, size)) {
		int boardSize = size / 3;

		sliceBoard(y, x, boardSize);
		sliceBoard(y, x + boardSize * 1, boardSize);
		sliceBoard(y, x + boardSize * 2, boardSize);
		sliceBoard(y + boardSize * 1, x, boardSize);
		sliceBoard(y + boardSize * 1, x + boardSize * 1, boardSize);
		sliceBoard(y + boardSize * 1, x + boardSize * 2, boardSize);
		sliceBoard(y + boardSize * 2, x, boardSize);
		sliceBoard(y + boardSize * 2, x + boardSize * 1, boardSize);
		sliceBoard(y + boardSize * 2, x + boardSize * 2, boardSize);
		
	}

	return;
}

int main()
{	
	int n;
	cin >> n;

	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			cin >> board[y][x];
		}
	}

	sliceBoard(0, 0, n);

	for (int i = 0; i < 3; ++i) {
		cout << result[i] << endl;
	}

}

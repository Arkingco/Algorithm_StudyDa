 #include<algorithm>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
using namespace std;

const int maxboardSize = 65;
int board[maxboardSize][maxboardSize];
vector<string> words;

bool checkBoard(int y, int x, int size) {
	int check = board[y][x];
	for (int boardy = y; boardy < y + size; ++boardy) {
		for (int boardx = x; boardx < x + size; ++boardx) {
			if (check != board[boardy][boardx]) {
				return false;
			}
		}
	}

	return true;
}

void quadTree(int y, int x, int size) {
	
	if (size == 1) {
		words.push_back(to_string(board[y][x]));
		return;
	}

	if (checkBoard(y, x, size)) {
		words.push_back(to_string(board[y][x]));

		return;
	}
	else {
		words.push_back("(");
		int thisSize = size / 2;
		quadTree(y, x, thisSize);
		quadTree(y, x + thisSize, thisSize);
		quadTree(y + thisSize, x, thisSize);
		quadTree(y + thisSize, x + thisSize, thisSize);
		words.push_back(")");
	}

}

int main()
{
	int n;
	cin >> n;

	string value;
	for (int i = 0; i < n; ++i) {
		cin >> value;

		for (int j = 0; j < value.size(); ++j) {
			board[i][j] = (int)value[j] - 48; 
		}
	}

	quadTree(0, 0, n);

	for (int i = 0; i < words.size(); ++i) {
		cout << words[i];
	}
}

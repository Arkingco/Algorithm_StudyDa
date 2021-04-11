#include<algorithm>
#include<iostream>
#include<vector>
#include<cstring>
#include<string.h>
#include<cmath>
#include<queue>
using namespace std;
typedef pair<int, int> pii;

vector<int> result;
vector<pii> house;
vector<pii> chic;


bool visited[51];
int dist = 987654321;
int board[51][51];
int n, m;

int getDistance(pii a, pii b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void play(int chicNumber, int select_chic) {

	if (chicNumber > chic.size()) {
		return;
	}

	if (select_chic == m) {

		result = vector<int>(house.size(), 10000000);
		for (int i = 0; i < chic.size(); ++i) {

			if (visited[i]) {
				for (int j = 0; j < house.size(); ++j) {
					result[j] = min(result[j], getDistance(chic[i], house[j]));
				}
			}
		}

		int sum = 0;
		for (int i = 0; i < house.size(); ++i) {
			sum = sum + result[i] ;
		}

		dist = min(dist, sum);
	}

	visited[chicNumber] = true;
	play(chicNumber + 1, select_chic + 1);

	visited[chicNumber] = false;
	play(chicNumber + 1, select_chic);

}

int main() { 

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	memset(visited, false, sizeof visited);
	memset(board, false, sizeof board);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];

			if (board[i][j] == 2) {
				chic.push_back({ i, j });
			}
			if (board[i][j] == 1) {
				house.push_back({ i, j });
			}
		}
	}

	play(0, 0);

	cout << dist << endl;
}

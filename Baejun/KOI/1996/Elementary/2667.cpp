// 정보올림피아드 1996년 초등부 1번
// 그래프를 사용하여 해결한다!

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int BOARD_MAX_N = 26;

int board[BOARD_MAX_N][BOARD_MAX_N];

int board_y[4]={-1, 0, +1, 0};
int board_x[4]={0, -1, 0, +1};

int n;

bool checkSize(int here_y, int here_x) {
	if((here_y >= n || here_y < 0) || (here_x >= n || here_x < 0)) {
		return false;
	} 
	return true;
}

int bfs(int here_y, int here_x, int ret) {

	board[here_y][here_x] = 0;
	int rete = ret+1;
	for(int i=0; i<4; ++i) {
		if(checkSize(here_y+board_y[i], here_x+board_x[i]) && board[here_y+board_y[i]][here_x+board_x[i]] != 0) {
			rete = bfs(here_y+board_y[i], here_x+board_x[i], rete);
		}
	}
	
	return rete;
}

int main() {
	
	cin >> n;
	

	
	for(int i=0; i<n; ++i ) {
		string a;
		cin >> a;
		
		for(int j=0; j<n; ++j) {
			board[i][j] = a[j] - '0';
		}
	}
	
	
	vector<int> result;
	int ret = 0;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			if(board[i][j] != 0) ret = bfs(i, j, 0);
			if(ret != 0) result.push_back(ret);
			ret = 0;
		}
	}
	
	sort(result.begin(), result.end());
	cout << result.size() << endl;
	for(int i=0; i<result.size(); ++i) {
		cout << result[i] << '\n';
	}
}
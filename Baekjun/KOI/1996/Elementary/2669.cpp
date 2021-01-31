#include<iostream>
#include<vector>
using namespace std;

const int MAX_N = 100;

int main() {
	
	vector<vector< bool> >board = vector< vector<bool> >(MAX_N, vector<bool>(MAX_N, false));
	for(int i=0; i<4; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		if(x1 > x2) swap(x1, x2);
		if(y1 > y2) swap(y1, y2);
		
		for(int ystart=y1; ystart<y2; ++ystart) {
			for(int xstart=x1; xstart < x2; ++xstart) {
				board[ystart][xstart] = true;
			}
		}
	}
	
	int ret = 0;
	for(int i=0; i<MAX_N; ++i) {
		for(int j=0; j<MAX_N; ++j) {
			if(board[i][j] == true) ret++;
		}
	}
	cout << ret << '\n';
}
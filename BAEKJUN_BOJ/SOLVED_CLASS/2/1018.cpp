#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

char chessFirstW[8][8] ={{'W','B','W','B','W','B','W','B'},
						{ 'B','W','B','W','B','W','B','W'},
						{ 'W','B','W','B','W','B','W','B'},
						{ 'B','W','B','W','B','W','B','W'},
						{ 'W','B','W','B','W','B','W','B'},
						{ 'B','W','B','W','B','W','B','W'},
						{ 'W','B','W','B','W','B','W','B'},
						{ 'B','W','B','W','B','W','B','W'},
};

char chessFirstB[8][8] ={ {'B','W','B','W','B','W','B','W'},
						{ 'W','B','W','B','W','B','W','B' },
						{ 'B','W','B','W','B','W','B','W' },
						{ 'W','B','W','B','W','B','W','B' },
						{ 'B','W','B','W','B','W','B','W' },
						{ 'W','B','W','B','W','B','W','B' },
						{ 'B','W','B','W','B','W','B','W' },
						{ 'W','B','W','B','W','B','W','B' }
};

char chess[51][51];
int main()
{
	int m, n;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> chess[i][j];
		}
	}

	int ret_min = 2500;
	for (int y = 0; y <= n - 8; ++y) {
		for (int x = 0; x <= m - 8; ++x) {

			int countFirstW = 0;
			int countFirstB = 0;

			for (int i = 0; i < 8; ++i) {
				for (int j = 0; j < 8; ++j) {
					if (chess[y + i][x + j] != chessFirstW[i][j]) {
						countFirstW++;
					}

					if (chess[y + i][x + j] != chessFirstB[i][j]) {
						countFirstB++;
					}
				}
			}
            
			ret_min = min(ret_min, min(countFirstW, countFirstB));
		}
	}

	cout << ret_min << endl;
}

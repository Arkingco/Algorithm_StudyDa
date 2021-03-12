#include<algorithm>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
using namespace std;

int board[100001] = { 0 };
int main()
{
	int n, k;
	cin >> n >> k;
    
    board[n] = 0;    
    
    for (int i = 0; i < n; ++i) {
        board[i] = n - i;
    }

    for (int i = n + 1; i <= 100001; ++i) {
        if (i % 2 == 0) {
            board[i] = min(board[i - 1] + 1, board[i / 2] + 1);
        }
        else {
            board[i] = board[i - 1] + 1;
        }
        

        board[i - 1] = min(board[i - 1], board[i] + 1);
    }

    cout << board[k] << endl;
}

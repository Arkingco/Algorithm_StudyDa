#include<iostream>
using namespace std;

int N;
int board[15];
int res = 0;

bool possible(int currentRow) {
    // 이전 퀸들의 위치들
    for (int i = 0; i < currentRow; i++) {
        // 같은 열에 있거나 대각선 상에 있을 경우 false 반환
        if (board[i] == board[currentRow] || (currentRow - i) == abs(board[i] - board[currentRow])) {
            return false;
        }
    }

    return true;
}

void setQueen(int row) {
    if (row == N) {
        res++;
    }
    else {
		// 이중for문 같은 역할
        for (int col = 0; col < N; col++) {
            board[row] = col;
			
            if (possible(row)) {
                setQueen(row + 1);
            }
        }
    }
}

int main(void) {
    cin >> N;

    setQueen(0);

    cout << res << '\n';

    return 0;
}
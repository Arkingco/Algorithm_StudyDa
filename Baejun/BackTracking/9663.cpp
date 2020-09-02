#include<iostream>
#include<vector>
using namespace std;

int n;

bool SearchQueen(int board[][100],int y ,int x ){
	bool check = true;
	for(int i=0; i<n; ++i) if(board[y][i] == 1) return false; // X축 기준으로 퀸이 있나 비교
	for(int i=0; i<n; ++i) if(board[i][x] == 1) return false; // Y축 기준으로 퀸이 있나 비교
	
	int y1 = y; int x2 = x;
	while(x != 0 && y != 0){ 
		y--; x--;
		y1++; x2--;
	}
	for(int i=0; i<n; ++i){
		if(board[i+y][i+x] == 1 || board[x2+i][y1-i] == 1) return false;	
	}
	return check;
}

//퀸의 좌표가 y , x 일 때 겹치지 않을 경우의 수 
int N_Queen(int board[][100] ,int y ,int x ,int count ){
	if(y == n || x == n) return 0;
	if(count == n) return 1;
	cout << y << " " << x << endl;
	cout << "value :" <<  SearchQueen(board, y , x) << endl;
	if(SearchQueen(board, y , x) == true){

		board[y][x] = 1;
		N_Queen(board, y+1 , x , count + 1);
		N_Queen(board , y , x+1, count + 1);
	}
	else { return 0;}
	return 0;
}
int main(){
	
	cin >> n;
	int sum=0;
	int board[100][100];
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			int eoard[100][100];
			sum = sum + N_Queen(eoard ,i , j , 0);
		}
	}
	cout << sum << endl;
}
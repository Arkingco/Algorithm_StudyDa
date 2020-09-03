#include<iostream>
#include<vector>
using namespace std;

const int SUDOKU_LENGTH = 9;

vector<pair<int,int>> location;

bool isAble(int board[][SUDOKU_LENGTH] , int order , int value){
	for(int i=0; i<SUDOKU_LENGTH; ++i){
		if(board[location[order].first][i] == value || board[i][location[order].second] == value) return false;
	}

	int y=location[order].first/3;
	int x=location[order].second/3;
	for(int i=y*3; i<(y*3)+3; ++i){
		for(int j=x*3; j<(x*3)+3; ++j){
			if(board[i][j] == value){
				return false;	
			} 
		}
	}
    return true;
}

bool isVale= false;
void sudoku(int board[][SUDOKU_LENGTH] , int order){
	
	if(order == location.size() && isVale==false){
		for(int i=0; i<SUDOKU_LENGTH; ++i){
			for(int j=0; j<SUDOKU_LENGTH; ++j){
				printf("%d ",board[i][j]);
			}
			cout <<"\n";
		}
		isVale=true;		
	} else if(isVale == true) return;
	else {
		for(int i=1; i<SUDOKU_LENGTH+1; ++i){
			if(isAble(board,order , i)){
				board[location[order].first][location[order].second] = i;
				sudoku(board , order+1);
				board[location[order].first][location[order].second] = 0;
			}
		}
	}
	return;
}
int main(){
	int board[SUDOKU_LENGTH][SUDOKU_LENGTH];
	for(int i=0; i<SUDOKU_LENGTH; ++i){
		for(int j=0; j<SUDOKU_LENGTH; ++j){
			int value;
			cin >> value;
			board[i][j] = value;
			if(value == 0) location.push_back(make_pair(i,j));
		}
	}
	sudoku(board , 0);
}
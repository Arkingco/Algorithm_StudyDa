#include<iostream>
using namespace std;

int n;
int board[15];
int count =0;

bool isAble(int cnt ) {
	for(int i=0; i<cnt; ++i){
		if(board[i] == board[cnt] || (cnt -i) == abs(board[i] - board[cnt]))
			return false;
	}
	return true;
}
void Queen(int cnt){
	if(cnt == n) count++;
	else {
		for(int i=0; i<n; ++i){
			board[cnt] = i;
			
			if(isAble(cnt)){
				Queen(cnt + 1);
			}
		}
	}
}
int main(){
	cin >> n;
	Queen(0);
	cout << count << endl;
}
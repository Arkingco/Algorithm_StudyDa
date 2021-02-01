#include<iostream>
using namespace std;


int n;
int dp[501][501];
int tryangle[501][501];
int INF = 987654321;
int angle(int y , int x){
	if(y==n || x == n) return 0;
	
	int& ret =  dp[y][x];
	if(ret != 0) return ret;
	ret = max(angle(y+1, x ) , angle(y+1 , x+1)) + tryangle[y][x];
	
	return ret;
}

int main(){
	cin >> n;
	
	for(int i=0; i<n; ++i){
		for(int j=0; j<i+1; ++j){
			cin >> tryangle[i][j];
		}
	}
	cout << angle(0,0) << endl;
}
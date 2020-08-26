#include<iostream>
using namespace std;

int n;
int stair[301];
int dp[301][301];
int up(int x , int status){
	
	if(x == n-1) return stair[x];
	// 마지막 계단은 반드시 밣아야 한다.
	if(x >= n) return -987654321;
	
	int& ret = dp[x][status];
	if(ret != 0) return ret;
	if(status == 1) return ret =  up(x+2 , 0) + stair[x];
	return ret =  max(up(x+1 , 1) , up(x+2 , 0)) + stair[x];
}
int main(){
	cin >> n;
	
	for(int i=0; i<n; ++i){
		cin >> stair[i];
	}
	
	cout << up(0 , 0) << endl;
}
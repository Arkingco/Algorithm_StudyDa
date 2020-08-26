#include<iostream>
using namespace std;

int n;
int stair[301];
int dp[301];
int main(){
	cin >> n;
	
	for(int i=0; i<n; ++i){
		cin >> stair[i];
	}
	
	//이 알고리즘의 핵심 포인트 stair[0]+stair[1] 은 결과상 될 수가 없음. 
	dp[0] = stair[0];
    dp[1] = max(stair[0]+stair[1], stair[1]);
    dp[2] = max(stair[0]+stair[2], stair[1]+stair[2]);
	
	for(int i=3;i<=n;i++) {
    dp[i] = max(dp[i-2] + stair[i], dp[i-3] + stair[i] + stair[i-1] );
	}

	cout << dp[n-1]<< endl;
}
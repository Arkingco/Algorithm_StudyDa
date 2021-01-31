#include<iostream>
using namespace std;

int n;
int stair[10005];
int dp[10005];
int main(){
	cin >> n;
	
	for(int i=3; i<n+3; ++i){
		cin >> stair[i];
	}
	
	
	for(int i=3;i<n+3;i++) {
    dp[i] = max(dp[i-2] + stair[i], dp[i-3] + stair[i] + stair[i-1] );
	dp[i] = max(dp[i-1], dp[i]);	
	}

	cout << dp[n+2]<< endl;
}
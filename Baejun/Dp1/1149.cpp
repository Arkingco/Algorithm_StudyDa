#include<iostream>
#include<vector>
using namespace std;


int n;
int paint[1001][1001];
int dp[1001][1001];
int main(){
	cin >> n;
	for(int i=1; i<=n; ++i){
		for(int j=0; j<3; ++j){
			int value;
			cin >> value;
			paint[i][j] = value;
		}
	}
	
	dp[0][0] = dp[0][1] = dp[0][2] = paint[0][0] = paint[0][1] = paint[0][2] = 0;
	
	for(int i=1; i<=n; ++i){
		dp[i][0] = min(dp[i-1][1] , dp[i-1][2]) + paint[i][0];
		dp[i][1] = min(dp[i-1][0] , dp[i-1][2]) + paint[i][1];
		dp[i][2] = min(dp[i-1][1] , dp[i-1][0]) + paint[i][2];
	}
	
	
	cout << min(dp[n][0] , min(dp[n][1] , dp[n][2])) << endl;
	
}
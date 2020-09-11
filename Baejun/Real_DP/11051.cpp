#include<iostream>
using namespace std;


long long int dp[1001][1001];
int main(){
	int n , m;
	cin >> n >> m ;
	dp[1][1]= 1;
	dp[1][0]= 1;
	for(int i=2; i<=n; ++i){
		dp[i][0] = 1;
		for(int j=1; j<=m; ++j){
			dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % 10007;
		}
	}
	cout << dp[n][m] << '\n';
}
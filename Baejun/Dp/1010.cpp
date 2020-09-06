#include<iostream>
using namespace std;

int dp[31][31];

int c(int n, int r) {
	int& ret = dp[n][r];
	if(ret != 0 ) return ret;
	if(n == r || r == 0) return 1;
	
	return ret = c(n-1 , r-1) + c(n , r-1);
}

int main(){
	int n , m ;
	
	int e;
	cin >> e;
	

	for(int i=0; i<31; ++i){
		dp[i][i] = dp[i][0] = 1;
		for(int j=1; j<=i; ++j){
		dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
		}
	}
	while(e--){
		cin >> n >> m;	
		cout<<dp[m][n] << '\n';
	}

}
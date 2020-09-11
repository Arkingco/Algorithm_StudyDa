#include<iostream>
using namespace std;


int main(){
	int n;
	int dp[31];
	cin >> n;
	dp[0] = 0;
	dp[1] = 3;
	dp[2] = 0;
	dp[3] = 13;
	
	for(int i=4; i<n; ++i){
		dp[i] = dp[i-2] + dp[i-4];
	}
	cout << dp[n-1] << endl;
}
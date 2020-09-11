#include<iostream>
using namespace std;

int main(){
	long long int dp[1000001];
	
	int n;
	cin >> n;
	dp[0] = 1;
	dp[1] = 2;
	for(int i=2; i<n; ++i){
		dp[i] = (dp[i-1] + dp[i-2])%15746;
	}
	cout << dp[n-1] << endl;
}
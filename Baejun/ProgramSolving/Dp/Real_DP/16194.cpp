#include<iostream>
using namespace std;


int main(){
	int dp[1001] , P[1001];
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i)
		cin >> P[i];
	
	for(int i=1; i<=n; ++i){
		dp[i] = P[i];
		for(int j=1; j<=i; ++j){
			dp[i] =  min(dp[i], dp[i-j] + P[j]);
			
		} 
		
	}
	cout << dp[n] << endl;
}
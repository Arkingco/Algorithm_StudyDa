#include<iostream>
using namespace std;

int n;
int dp[16] , T[16] , P[16];
int main(){
	cin >> n;
	for(int i=0; i<n; ++i){
		cin >> T[i] >> P[i];
	}
	for(int i=n-1; i>=0; --i){
		int next = i + T[i];
		if( i + T[i] > n ){
			dp[i] = dp[i+1];
		} else {
			dp[i] = max( dp[i + 1], dp[i+T[i]] + P[i] );
		}
	}
	cout << dp[0] << endl;
}
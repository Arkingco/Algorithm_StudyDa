#include<iostream>
using namespace std;
int dp[16];
int schedule[16];
int T[16];
int P[16];
int main(){
	int n;
	cin >> n;
	for(int i=0; i<n; ++i){
		int a , b;
		cin >> a >> b;
		T[i] = a;
		P[i] = b;
	}
	
	
	for(int i=0; i<n; ++i){
		dp[i] = 0;
		for(int j=i; j<n; ++j){
			dp[n-1] = max(dp[j] + P[j] , dp[n-1]);
		}
	}
	
	cout << dp[n-1] << endl;
}
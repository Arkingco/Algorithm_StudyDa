#include<iostream>
#include<vector>
using namespace std;

int n;
int list[1001];
int dp[10001];
int dp1[1001];
int main(){
	cin >> n;
	for(int i=0; i<n; ++i){
		cin >> list[i];
	}
	for(int i=0; i<n; ++i){
		dp[i] = 1;
		dp1[n-i-1] = 1;
		for(int j=0; j<i; ++j){
			  if (list[i] > list[j] &&  dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
			  if (list[n-i-1] > list[n-j-1] && dp1[n-j-1] + 1 > dp1[n-i-1]) dp1[n-i-1] = dp1[n-j-1] + 1;
			}
				
	}
	
	int ret=0;
	for(int i=0; i<n; ++i){
		ret = max(ret , dp[i] + dp1[i]);
	}
	cout << ret-1 << endl;
}
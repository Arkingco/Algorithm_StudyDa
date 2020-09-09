#include<iostream>
using namespace std;

int count = 0;
int n;
int dp[12];
int dp2[12];
//재귀
int Top_down(int n){
	int& ret = dp2[n];
	if(ret != 0) return ret;
	if(n < 0) return 0;
	if(n == 0) return 1;
	count++;
	return ret = Top_down(n-1) + Top_down(n-2) + Top_down(n-3);
}
int main(){
	
	int T;
	cin >> n;
	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 4;
	//반복문 DP
	for(int i=3; i<n; ++i){
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
	}
	cout << dp[n-1] << endl;
	cout << Top_down(n) << endl;
	cout << count << endl;
	
}
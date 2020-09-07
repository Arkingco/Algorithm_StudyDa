#include<iostream>
using namespace std;

int dp[100001];
int arr[100001];
int main(){
	int n;
	cin >> n;
	for(int i=0; i<n; ++i){
		cin >> arr[i];
	}
	dp[0] = arr[0];
	int maxval = dp[0];
	for(int i=1; i<n; ++i){
		
		dp[i] = max(dp[i-1] + arr[i] , arr[i]);
		maxval = max(maxval , dp[i]);
		cout << "dp[i] : "<<dp[i] << " " << dp[i-1] + arr[i] << "  " << arr[i] << endl;
	}
	cout << maxval << endl;
}
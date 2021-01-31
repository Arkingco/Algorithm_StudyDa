#include<iostream>
using namespace std;

int dp[1001] , A[1001];

int main(){
	int n;
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> A[i];
	
	for(int i=0; i<n; ++i){
		dp[i] = 1;
		for(int j=0; j<i; ++j){
			if(A[i] > A[j] && dp[i] < dp[j]+ 1){
				dp[i] = dp[j] + 1;
			}
		}
		for(int z=0; z<i; ++z){
			cout << dp[z] << " ";
		}
		cout << endl;
	}
		cout << dp[n-1] << endl;
	
}
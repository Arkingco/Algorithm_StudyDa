#include<iostream>
using namespace std;

int dp[10001] = {1} , coin[101];
int main(){
	int n,k;
	
	cin >> n>> k;
	for(int i=1; i<=n; ++i){
		cin >> coin[i];
		//coin[i] 이전 까지는 고려 할 필요가 없다.
		for(int j=coin[i]; j<=k; ++j){
			dp[j] = dp[j] + dp[j-coin[i]];
			cout <<"["<<dp[j] << " "<<  j-coin[i]<< "] ";
		}
		cout << endl;
	} 
	
	cout << dp[k] << endl;
}
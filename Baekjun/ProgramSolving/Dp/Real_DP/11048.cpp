#include<iostream>
using namespace std;

int dp[1001][1001];
int map[1001][1001];
int main(){
	int n , m;
	cin >> n >> m;
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			cin >> map[i][j];
	
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			int temp = max( max(dp[i-1][j] , dp[i-1][j-1] ) , dp[i][j-1]);
			dp[i][j] = temp + map[i][j];
			
		}
	}
	cout << dp[n-1][m-1] << '\n';
}
#include<iostream>
#include<vector>
using namespace std;

int n , w ,k;
int dp[102][100002];
vector<pair<int,int>> valuable;
int main(){
	cin >> n >> k;	
	valuable.push_back(make_pair(0,0));
	for(int i=0; i<n; ++i){
		int W , V;
		cin >> W >> V;
		valuable.push_back(make_pair(W,V));
	}	
	
	for(int i=1; i<=n; ++i){
		for(int j=0; j<=k; ++j){
			if(j<valuable[i].first) dp[i][j]=dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j] , dp[i-1][j-valuable[i].first] + valuable[i].second);	
			
			
		}
	}
	cout << dp[n][k] << endl;
}
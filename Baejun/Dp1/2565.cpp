#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int , int>> list;
int n;
int dp[501];


int main(){
	cin >> n;
	for(int i=0; i<n; ++i){
		int a,b;
		cin >> a >> b;
		list.push_back(make_pair(a,b));
	}
	sort(list.begin() , list.end());
	
	int ret = 0;
	for(int i=0; i<n; ++i){
		dp[i] = 1;
		for(int j=0; j<=i; ++j){
			if(list[i].second > list[j].second && dp[i] < dp[j] + 1 ) dp[i] = dp[j] + 1;
		}	
		ret = max(ret , dp[i]);
	}
	cout << list.size() - ret << endl;
	
	
}
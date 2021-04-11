#include<algorithm>
#include<iostream>
#include<vector>
#include<cstring>
#include<string.h>
#include<cmath>
#include<queue>
#include<map>
using namespace std;

const int MAXe = 50005;
const int INF = 987654321;
int dp[MAXe];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= MAXe-1; ++i) {
		dp[i] = INF;
	}
	for (int i = 1; i * i <= MAXe-1; ++i) {
		dp[i * i] = 1;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= sqrt(i); ++j) {
			dp[i] = min(dp[i], dp[j * j] + dp[i-(j * j)]);
		}
	}

	cout << dp[n] << endl;
}
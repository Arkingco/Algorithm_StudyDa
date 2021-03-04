#include<iostream>
#include<cstring>
using namespace std;

int dp[100] = { 1, 1 };
int fibo(int n) {

	if (dp[n] != 0) return dp[n];

	if (n == 0 || n == 1) {
		return 1;
	}

	return dp[n] = fibo(n - 1) + fibo(n - 2);
}

int main()
{
	int n;
	cin >> n;

	memset(dp, 0, sizeof dp);

	fibo(50);

	int dp0[100] = { 1, 0 };
	int dp1[100] = { 0, 1 };
	dp[0] = 1; dp[1] = 1;

	for (int i = 2; i <= 50; ++i) {
		dp0[i] = dp[i - 2];
		dp1[i] = dp[i -1];
	}

	for (int i = 0; i < n; ++i) {
		int value;
		cin >> value;

		cout << dp0[value] << " " << dp1[value] << endl;
	}
	
}

#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
#include<math.h>
#include<cstdio>
using namespace std;

int bino(int n, int k) {
	if (n == k) return 1;
	if (k == 0) return 1;
	return bino(n - 1, k - 1) + bino(n - 1, k);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	cout << bino(n, k) << endl;
}

#include<algorithm>
#include<iostream>
#include<vector>
#include<cstring>
#include<string.h>
#include<cmath>
#include<queue>
#include<map>
using namespace std;
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	map<string, string> result;

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		string a, b;
		cin >> a >> b;

		result[a] = b;
	}
	for (int i = 0; i < m; ++i) {
		string a;
		cin >> a;

		cout << result[a] << '\n';
	}
}
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;

typedef long long int lli;
bool era[1000001];
int main()
{
	int n, m;
	cin >> n >> m;	

	memset(era, false, sizeof era);

	// 1은 소수가 아님
	era[1] = true;
	for (int i = 2; i <= sqrt(m); ++i) {
		for (int j = i*2; j <= m; j = j+i) {
			era[j] = true;
		}
	}

	for (int i = n; i <= m; ++i) {
		if (era[i] == false) {
			cout << i << '\n';
		}
	}
}

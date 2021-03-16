#include<algorithm>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<deque>
#include<map>
using namespace std;


int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	long long int t;
	cin >> t;
	long long int M, N, x, y;
	long long int dalx, daly;

	
	while (t--) {	
		cin >> M >> N >> x >> y;

		bool checkResult = false;
		dalx = daly = 1;

		if (M < N) {
			long long int change = M;
			M = N;
			N = change;

			change = y;
			y = x;
			x = change;
		}
		
		daly = x;
		long long int na = M % N;
		long long int i;

		for (i = 0; i <= M; ++i) {
			if (daly == y) {
				checkResult = true;
				break;
			}
			daly = (daly + na) % N;
			if (daly == 0) daly = N;
		}

		if (!checkResult) {
			cout << "-1" << '\n';
		}
		else {
 			cout << x + (i * M) << '\n';
		}
		
	}
}
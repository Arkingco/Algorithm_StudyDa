#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

typedef long long int lli;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<lli> anser(n);
	lli start = 1;
	lli end = 0;

	for (int i = 0; i < n; ++i) {
		cin >> anser[i];

		end = max(end, anser[i]);
	}

	lli result = 0;
	while (start <= end) {

		lli mid = (start + end) / 2;

		lli countM = 0;
		for (int i = 0; i < n; ++i) {
			countM = countM + (anser[i] / mid);
		}

		if (countM < m) {
			end = mid - 1;
		}
		// 많이 만드는건 문제가 되지 않는다.
		else if (countM >= m) {
			result = max(result, mid);
			start = mid + 1;
		}

	}
	cout << result << endl;
}

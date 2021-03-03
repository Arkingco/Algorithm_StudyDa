#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

int main()
{
	cin.tie(0);

	int n, m;
	cin >> n;

	vector<int> anser(n);
	for (int i = 0; i < n; ++i) {
		cin >> anser[i];
	}
	sort(anser.begin(), anser.end());
	
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int value;
		cin >> value;

		auto up = upper_bound(anser.begin(), anser.end(), value);
		auto down = lower_bound(anser.begin(), anser.end(), value);

		printf("%d ",up - down);
	}
}

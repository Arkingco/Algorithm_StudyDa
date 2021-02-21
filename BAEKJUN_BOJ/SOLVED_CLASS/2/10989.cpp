#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
#include<math.h>
#include<cstdio>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> anser(10001, 0);
	for (int i = 0; i < n; ++i) {
		int value;
		cin >> value;
		anser[value]++;
	}

	for (int i = 1; i <= 10000; ++i) {
		for (int j = 0; j < anser[i]; ++j) {
			printf("%d\n", i);
		}
		
	}
}

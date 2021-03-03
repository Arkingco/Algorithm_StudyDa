#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
#include<math.h>
#include<stack>
#include<queue>
#include<stdio.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	int n;
	cin >> n;
	
	vector<int> anser(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", anser[i]);
	}

	sort(anser.begin(), anser.end());

	for (int i = 0; i < n; ++i) {
		cout << anser[i] << '\n';
	}
}

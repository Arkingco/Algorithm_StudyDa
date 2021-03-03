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

typedef long long int lli;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	lli start = 0;
	lli end = 0;
	lli n, m;
	cin >> n >> m;
	
	vector<lli> array(n + 1);
	
	for (int i = 0; i < n; ++i) {
		cin >> array[i];
		end = max(end, array[i]);
	}

	lli mCount = 0;
	while (start <= end) {
		
		lli mid = (start + end) / 2;

		lli count = 0;
		for (int i = 0; i < n; ++i) {
			if (mid < array[i]) {
				count = count + (lli)(array[i] - mid);
			}
		}

		if (count < m) {
			end = mid - 1;
		} else if(count >= m){
			mCount = max(mCount, mid);
			start = mid + 1;
		}
	}

	cout << mCount << endl;
	
}

#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> anser(n);

	int low = 1000001;
	for (int i = 0; i < n; ++i) {
		cin >> anser[i];

		low = min(low, anser[i]);
	}

	int mCount = 0;
	while (true) {

		mCount = 0;
		for (int i = 0; i < n; ++i) {
			mCount = mCount + (anser[i] / low);
		}

		cout << mCount << endl;

		if(mCount > m) {
			
		}
		else {
			low = low + (low / 2);
			
		}

	
	}
	
}

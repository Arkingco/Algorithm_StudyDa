#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
#include<math.h>
#include<cstdio>
using namespace std;

int returnIndex(int index, int n) {
	return index % n;
}

int main()
{
	cout.tie(0); cin.tie(0); ios::sync_with_stdio(0);

	int n, k;
	cin >> n >> k;

	vector<int> anser(n + 1);
	vector<int> result(n, -1);
	for (int i = 0; i < n; ++i) {
		anser[i] = i + 1;
	}

	int index = 0;
	for (int i = 0; i < n; ++i) {

		for (int j = 0; j < k - 1; ++j) {
			index++;
			index = returnIndex(index, n);
			if (anser[index] == -1) {
				j = j - 1;
			}


		}
		result[i] = anser[index];
		anser[index] = -1;
		for (int z = 0; z < n; ++z) {
			if (anser[index] == -1) {
				index++;
				index = returnIndex(index, n);
			}
			else {
				break;
			}
		}
	}

	if (n == 1) {
		cout << "<1>" << endl;
	}
	else {
		printf("<%d,", result[0]);
		for (int i = 1; i < n - 1; ++i) {
			printf(" %d,", result[i]);
		}
		printf(" %d>", result[n - 1]);
	}
	
}

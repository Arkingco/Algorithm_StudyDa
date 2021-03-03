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


	while (true) {
		vector<int> array(3);
		for (int i = 0; i < 3; ++i) {
			cin >> array[i];
		}

		sort(array.begin(), array.end());

		int a = array[0];
		int b = array[1];
		int c = array[2];

		if (a == 0 && b == 0 && c == 0) {
			break;
		}

		cout << (((a * a) + (b * b)) == (c * c) ? "right" : "wrong") << endl;
	}
	
}

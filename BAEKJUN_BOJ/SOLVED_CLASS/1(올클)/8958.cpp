#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

int main() {

	int n;
	cin >> n;
	
	vector<string> anser(n);
	for (int i = 0; i < n; ++i) {
		cin >> anser[i];
	}

	for (int i = 0; i < n; ++i) {

		int ret = 0;
		int Ocount = 0;
		for (int j = 0; j < anser[i].size(); ++j) {
			
			if (anser[i][j] == 'O') {
				Ocount = Ocount + 1;
			}
			else {
				Ocount = 0;
			}
			ret = ret + Ocount;
		}
		cout << ret << '\n';
	}
	
}
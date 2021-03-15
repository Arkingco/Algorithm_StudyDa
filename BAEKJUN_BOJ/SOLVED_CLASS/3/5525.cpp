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

	int n, m;
	string s;
	cin >> n >> m >> s;

	int countSize = 2*n + 1;
	int count = 0;
	int checkCount = 0;
	char lastWord = '0';
	for (int i = 0; i < m; ++i) {
		
		if (checkCount == 0 && s[i] == 'I') {
			checkCount++;
			lastWord = 'I';
		}
		else if (checkCount == 0 && s[i] == 'O') continue;
		else {
			if (checkCount != 0 && s[i] == lastWord) {
				checkCount = 0;
				i--;
			}
			else {
				checkCount++;
				lastWord = s[i];

				if (countSize == checkCount) {
					count++;
					checkCount = checkCount - 2;
					lastWord = 'I';
				}
			}
		}
	}

	cout << count << endl;
}
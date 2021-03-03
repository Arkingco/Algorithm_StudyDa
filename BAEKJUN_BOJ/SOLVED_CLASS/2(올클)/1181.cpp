#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<string> anser[100];

	for (int i = 0; i < n; ++i) {
		string value;
		cin >> value;

		// 글자수 정렬
		anser[value.size()].push_back(value);
	}

	for (int i = 1; i <= 50; ++i) {
		if (anser[i].size() == 0) {
			continue;
		}

		// 사전순으로 정렬
		sort(anser[i].begin(), anser[i].end());
		// 중복제거
		anser[i].erase(unique(anser[i].begin(), anser[i].end()), anser[i].end());
	}

	for (int i = 1; i <= 50; ++i) {
		if (anser[i].size() == 0) {
			continue;
		}

		for (int j = 0; j < anser[i].size(); ++j) {
			if (anser[i][j] != "")
				cout << anser[i][j] << endl;
		}
	}
}

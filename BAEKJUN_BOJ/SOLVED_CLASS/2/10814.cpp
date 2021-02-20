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

	vector<string> anser[201];
	for (int i = 0; i < n; ++i) {
		int age;
		string name;

		cin >> age >> name;

		anser[age].push_back(name);
	}

	for (int i = 0; i < 201; ++i) {

		for (int j = 0; j < anser[i].size(); ++j) {
			cout << i << " " << anser[i][j] << '\n';
		}
	}
}

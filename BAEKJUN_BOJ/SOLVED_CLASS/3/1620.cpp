#include<algorithm>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	map<string, string> mymap;
	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		string value;
		cin >> value;

		mymap.insert({ value, to_string(i) });
		mymap.insert({ to_string(i), value });
	}

	for (int i = 0; i < m; ++i) {
		string value;
		cin >> value;
		cout << mymap[value] << '\n';
	}
}



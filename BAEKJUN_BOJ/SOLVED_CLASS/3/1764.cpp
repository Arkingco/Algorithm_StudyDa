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
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	map <string, bool> hear;
	vector<string> word;
	
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		string name;
		cin >> name;

		hear.insert({ name, true });
	}

	for (int i = 0; i < m; ++i) {
		string name;
		cin >> name;

		if (hear[name]) {
			word.push_back(name);
		}
	}

	sort(word.begin(), word.end());

	cout << word.size() << '\n';
	for (int i = 0; i < word.size(); ++i) {
		cout << word[i] << '\n';
	}
}

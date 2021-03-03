#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;

int main() {
	
	int t;
	int average = 0;
	int midle = 0;
	int maxFind = 0;
	int minSideMax = 0;
	cin >> t;

	vector<int> anser(t);
	for (int i = 0; i < t; ++i) {
		cin >> anser[i];
	}

	sort(anser.begin(), anser.end());


	for (int i = 0; i < t; ++i) {
		average = average + anser[i];
	}
	average = round((float)average / t);

	midle = anser[t / 2];

	vector<int> array(8010);
	vector<int> bean;
	for (int i = 0; i < t; ++i) {
		array[anser[i]+4000]++;
	}
	int be = 0;
	for (int i = 0; i < 8002; ++i) {
		if (be < array[i]) {
			be = array[i];
		}
	}
	for (int i = 0; i < 8002; ++i) {
		if (array[i] == be) {
			bean.push_back(i-4000);
		}
	}
	sort(bean.begin(), bean.end());
	if (bean.size() == 1) {
		maxFind = bean[0];
	}
	else {
		maxFind = bean[1];
	}

	minSideMax = anser[t - 1] - anser[0];

	cout << average << endl;
	cout << midle << endl;
	cout << maxFind << endl;
	cout << minSideMax << endl;
}

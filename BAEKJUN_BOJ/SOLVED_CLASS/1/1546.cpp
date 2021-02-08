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

	vector<double> anser(n);
	for (int i = 0; i < n; ++i) {
		cin >> anser[i];
	}

	sort(anser.begin(), anser.end(), greater<double>());

	double ret = 0;
	for (int i = 0; i < n; ++i) {
		ret = ret + ((anser[i] / anser[0]) * 100);
	}

	cout << ret / n << endl;
}
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
using namespace std;

const int N = 51;
int main() {

	int n;
	cin >> n;
	vector<int> sizeX(N);
	vector<int> sizeY(N);
	vector<int> anser(N);

	for(int i=0; i<n; ++i) {
		int x, y;
		cin >> x >> y;
		sizeX[i] = x;
		sizeY[i] = y;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) continue;
			// 많이 비교되는 값을 상승 시켜서 등수를 매긴다. 
			if (sizeX[i] > sizeX[j] && sizeY[i] > sizeY[j]) {
				anser[j]++;
			}
		}
	}	
	for (int i = 0; i < n; i++) {
		cout << anser[i] + 1 << " ";
	}
}
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

int getValue(int growHeight, int value) {

	int workingTimeValue = 0;
	if (growHeight > value) {
		workingTimeValue = growHeight - value;
	}
	else if (growHeight < value) {
		workingTimeValue = (value - growHeight) * 2;
	}

	return workingTimeValue;
}

int main()
{
	pair<int, int> bestCost; bestCost.first = 999999999; bestCost.second = 0;
	vector<vector<int> > grow(501, vector<int>(501, 0));
	int minHeight = 999999;
	int maxHeight = 0;
	
	int n, m, b;
	cin >> n >> m >> b;
	

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int value;
			cin >> value;
			grow[i][j] = value;

			maxHeight = maxHeight + value;
			minHeight = min(minHeight, value);
		}
	}

	vector<int> workingTimeSet;

	maxHeight = (maxHeight + b) / (n * m); 
	for (int growHeight = minHeight; growHeight <= maxHeight; ++growHeight) {

		int workingTimeValue = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {

				int getVal = getValue(growHeight, grow[i][j]);
				workingTimeValue = workingTimeValue + getVal;
			}
		}

		if (bestCost.first > workingTimeValue) {
			bestCost.first = workingTimeValue;
			bestCost.second = growHeight;
		} 

		if (bestCost.first == workingTimeValue) {
			bestCost.second = max(bestCost.second, growHeight);
		}
		
	}

	cout << bestCost.first << " " << bestCost.second;
}

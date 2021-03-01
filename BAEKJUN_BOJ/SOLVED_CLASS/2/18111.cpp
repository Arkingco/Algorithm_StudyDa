#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

int getValue(int growHeight ,int value) {
	int workingTimeValue = 0;
	while (true) {
		if (growHeight > value) {
			workingTimeValue = workingTimeValue + 1;
			value = value + 1;
		}
		else if (growHeight < value) {
			workingTimeValue = workingTimeValue + 2;
			value = value - 1;
		}
		else {
			break;
		}
	}

	return workingTimeValue;
}

int main()
{
	pair<int, int> bestCost; bestCost.first = 999999999; bestCost.second = 0;
	int maxHeight = 0;
	int n, m, b;
	cin >> n >> m >> b;
	vector<vector<int> > grow(501, vector<int>(501,0));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int value;
			cin >> value;
			grow[i][j] = value;

			maxHeight = maxHeight + value;
		}
	}

	vector<int> workingTimeSet;
	
	maxHeight = (maxHeight + b) / (n * m);
	for (int growHeight = 0; growHeight <= maxHeight; ++growHeight) {

		int workingTimeValue = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				
				// getValue() = 입력받은 수를 growHeight와 비교하여 작으면 더해주고 크면 빼주면서 growHeight 값과 같게 만든다.
				// return = 같게 만들 때 필요한 횟수
				int getVal = getValue(growHeight, grow[i][j]);
				workingTimeValue = workingTimeValue + getVal;

			}
		}

		if (bestCost.first > workingTimeValue) {
			bestCost.first = workingTimeValue;
			bestCost.second = growHeight;
		}
	}

	cout << bestCost.first << " " << bestCost.second;
}

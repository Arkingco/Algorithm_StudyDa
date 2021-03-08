#include<algorithm>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

int minCount = 99999999;
bool isOff[10];

bool checkValue(string value) {

	bool check;
	for (int i = 0; i < value.size(); ++i) {

		int intValue = (int)value[i] - 48;
		check = true;

		if (!isOff[intValue]) check = false;

		if (!check) return false;
	}
	
	return true;
}

int main()
{
	int n;
	int m;
	cin >> n >> m;
	
	memset(isOff, true, sizeof isOff);

	for (int i = 0; i < m; ++i) {
		int index;
		cin >> index;
		isOff[index] = false;
	}

	for (int value = 0; value < 1000001; ++value) {

		// value에 들어가는 수가 지금 가지고 있는 버튼으로 만들 수 있는 숫자라면
		// return true 아니면 return false;
		if (!checkValue(to_string(value))) continue;

		int valuesize = to_string(value).size();
		minCount = min(minCount, abs(value - n) + valuesize);
	}

	minCount = min(minCount, abs(n - 100));
	cout << minCount << endl;
}

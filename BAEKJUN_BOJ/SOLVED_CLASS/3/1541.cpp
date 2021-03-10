#include<algorithm>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;

int main()
{
	vector<int> words;
	string value;
	cin >> value;

	words.push_back(0);
	int thisNumber = 0;
	int numberLength = 1;
	for (int back = value.size()-1; back >= 0; --back) {

		if (value[back] == '+' || value[back] == '-') {
			words.push_back(thisNumber);
			if (value[back] == '-') words.push_back(-1);

			numberLength = 1;
			thisNumber = 0;
		}
		else {
			thisNumber = thisNumber + (numberLength * ((int)value[back] - 48));

			numberLength = numberLength * 10;
		}
	}
	words.push_back(thisNumber);


	for (int back = words.size() - 1; back >= 0; --back) {
		if (words[back] == -1) {
			words[back - 1] = words[back] * words[back - 1];
			words[back - 2] = words[back] * words[back - 2];
			words[back] = 0;
		}
	}

	int result = 0;
	for (int i = 0; i < words.size(); ++i) {
		result = result + words[i];
	}

	cout << result << '\n';
}

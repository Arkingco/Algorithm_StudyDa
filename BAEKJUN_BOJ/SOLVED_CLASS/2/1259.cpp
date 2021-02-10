#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

bool check(string value) {
	for (int i = 0; i < value.size(); ++i) {
		int indexi = i;
		int indexj = value.size() - 1;
		if (value[indexi] != value[indexj - i]) return false;
	}

	return true;
}
int main()
{
	string value = "";
	while (true) {
		cin >> value;

		if (value == "0") break;

		if (check(value)) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}

	}
}

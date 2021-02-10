#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

bool check(string value) {
	for (int i = 0; i < value.size()-2; ++i) {
		if (value[i] == '6' && value[i + 1] == '6' && value[i + 2] == '6') {
			return true;
		}
	}
	return false;
}

int main()
{

	int count = 0;
	int n, i;
	cin >> n;
	for (i = 100; i < 21000000; ++i) {

		if (check(to_string(i))) {
			count++;
		}

		if (count == n) break;
	}
	                                                                                                                                                                                                                                         
	cout << i << endl;
}

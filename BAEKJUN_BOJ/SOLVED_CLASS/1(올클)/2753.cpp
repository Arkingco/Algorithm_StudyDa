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

	if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0) {
		cout << "1" << endl;
	}
	else {
		cout << "0" << endl;
	}
}
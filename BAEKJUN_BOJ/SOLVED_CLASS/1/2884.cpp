#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

int main() {

	int h, m;
	cin >> h >> m;

	if (m < 45) {
		if (h == 0) {
			h = 23;
		}
		else {
			h = h - 1;
		}
		m = 60 - ((m - 45) * -1);
	}
	else {
		m = m - 45;
	}

	cout << h << " " << m << endl;
}
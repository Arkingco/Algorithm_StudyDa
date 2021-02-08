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

	int A[6] = { 90, 80, 70, 60, 1000, 0 };
	char anser = 'A';
	for (int i = 0; i < 6; ++i) {
		if (A[i] <= n) {
			cout << anser << endl;
			break;
		}
		else {
			anser++;
		}
	}
}
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
using namespace std;

int main() {

	int a, b;
	cin >> a >> b;

	if (a > b) {
		cout << '>' << endl;
	}
	else if (a == b) {
		cout << "==" << endl;
	}
	else {
		cout << '<' << endl;
	}
}
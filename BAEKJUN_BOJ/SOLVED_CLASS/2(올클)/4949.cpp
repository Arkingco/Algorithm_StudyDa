#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
#include<math.h>
#include<stack>
#include<queue>
#include<stdio.h>
using namespace std;

typedef long long int lli;



bool check(string value) {
	char A[3] = { '(', '[', '{' };
	char B[3] = { ')', ']', '}' };

	
	stack<char> anser;
	for (int i = 0; i < value.size(); ++i) {

		for (int j = 0; j < 3; ++j) {
			if (A[j] == value[i]) {
				anser.push(A[j]);
			}

			if (B[j] == value[i]) {
				if (anser.empty() || anser.top() != A[j]) {
					return false;
				}
				else {
					anser.pop();
				}
			}
		}
	}

	if (anser.empty()) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	while (true) {
		string value;
		getline(cin, value);

		if (value == ".") break;

		if (check(value)) { 
			cout << "yes" << '\n';
		}
		else {
			cout << "no" << '\n';
		}
	}
}

#include<iostream>
#include<string>
using namespace std;

int main() {
	int T;
	cin >> T;

	while (T--) {
		string S;
		int n;

		cin >> n;
		cin >> S;
        
		for (int j = 0; j < S.size(); ++ j) {
			for (int i = 0; i < n; ++i) {
				cout << S[j];
			}
		}
		cout << '\n';

	}
}
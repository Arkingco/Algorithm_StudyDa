#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
using namespace std;

int main() {
	
	string S;
	cin >> S;

	char CH = 'A';
	char ch = 'a';

	vector<int> anser(27, 0);

	for (int i = 0; i < S.size(); ++i) {
		// 대문자
		if (S[i] < 'a') {
			anser[S[i] - 'A']++;
		} 
		else {
			anser[S[i] - 'a']++;
		}
	}
	
	int retMax = 0;
	for (int i = 0; i < 26; ++i) {
		retMax = max(retMax, anser[i]);
	}

	int count = 0, j;
	for (int i = 0; i < 26; ++i) {
		if (anser[i] == retMax) {
			j = i;
			count++;
		}
	}
	
	if (count > 1) {
		cout << "?" << '\n';
	} 
	else {
		cout << (char)(j + 'A') << '\n';
	}


}
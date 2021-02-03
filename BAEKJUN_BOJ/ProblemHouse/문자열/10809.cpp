#include<iostream>
#include<cstring>
using namespace std;

int main() {
	
	char S[101], ch;
	int anser[26];
	
	memset(anser, -1, sizeof anser);
	// S도 값을 할당하는 이유는 배열에 쓰래기 값이 들어가는데 그 값이
	// 아래 비교 for문에서 맞는값으로 인식을 해서 들어갈 수도 있기때문
	memset(S, -1, sizeof S);

	cin >> S;

	for (int i = 0; i < 100; ++i) {
		ch = 'a';
		for (int j = 0; j < 26; ++j) {
			if (ch == S[i] && anser[j] == -1) {
				anser[j] = i;
			}
			// char ++ 를 하면 자동으로 업캐스트가 된다.
			ch++;
		}
	}
	
	for (int i = 0; i < 26; ++i) {
		cout << anser[i] << " ";
	}
}
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
using namespace std;

int main() {
	
	string a, b;
	cin >> a >> b;

	// 문자열 반대로 뒤집기
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	// 뒤집은 문자열 int 변환
	int a1 = atoi(a.c_str());
	int a2 = atoi(b.c_str());

	// ><
	cout << (a2 > a1 ? a2 : a1) << endl;
}
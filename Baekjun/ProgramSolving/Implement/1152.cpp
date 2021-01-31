#include<iostream>
#include<string>
using namespace std;

int main() {
	string a;
	
	// 공백 포함 입력 받기
    getline(cin, a);
	
	const char space = ' ';
	int ret = (a[0] == space ? 0 : 1 );
	for(int i=0; i<a.length(); ++i) {
		if(a[i] != 0 && a[i] == space && a[i-1] == space) {
			ret--;
			break;
		}
		if(a[i] == space) ret++;
	}
	if(a[a.length()-1] == ' ') ret--;
	cout << ret << endl;
	
}
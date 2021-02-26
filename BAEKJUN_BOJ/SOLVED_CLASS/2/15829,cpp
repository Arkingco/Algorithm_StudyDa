#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
#include<math.h>
#include<cstdio>
using namespace std;

const int charTOint = 96;
const int moduler = 1234567891;
int main()
{
	cout.tie(0); cin.tie(0); ios::sync_with_stdio(0);

	int n;
	cin >> n; 
	
	int result = 0;
	for (int i = 0; i < n; ++i) {
		char a;
		cin >> a;

		int multipl = 1;
		for (int j = 0; j < i; ++j) {
			multipl = ((multipl * 31) % moduler) % moduler;
		}
		result = (result + (multipl * (int)(a-charTOint))) % moduler;
	}

	cout << result << endl;
}

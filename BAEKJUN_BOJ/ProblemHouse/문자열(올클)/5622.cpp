#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
using namespace std;

int main() {
	
	string a;
	cin >> a;

	int retSet[27]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
	int ret = 0;

	for (int i = 0; i < a.size(); ++i) {
		ret += retSet[(a[i] - 'A')];
	}
	cout << ret+a.size() << '\n';
}
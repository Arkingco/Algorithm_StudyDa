#include<iostream>
using namespace std;

int anser[1000000] = { 0, };

int findNewYear(int n) {
	// 기저사례
	if(n > 1000000) return 0;
	
	int& ret = anser[n];
	if(ret != 0) return 0;
	
	ret = n;
	
	return findNewYear(n + 2020) | findNewYear(n + 2021);
}

int main() {
	
	int t;
	cin >> t;
	
	findNewYear(2020);
	findNewYear(2021);
	
	while(t--) {
		int n;
		cin >> n;
		
		if(anser[n] != 0) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}
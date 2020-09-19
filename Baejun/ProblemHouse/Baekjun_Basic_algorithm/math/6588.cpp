#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

const int MAX_VALUE = 1000000;

bool eratose[MAX_VALUE];
int main(){
	eratose[1] = true;
	for(int i=2; i<=sqrt(MAX_VALUE); ++i){
		if(eratose[i] == true) continue;
		for(int j=i; i*j<=MAX_VALUE; j++){
			eratose[i*j] = true;
		}
	}
	
	int  T, n;
	while(n != 0){
		cin >> n;
		bool isable = true;
		for(int i=1; i<n; ++i){
			if(eratose[i] == false && eratose[n-i] == false && isable){
				cout << n <<" = " << i << " + " << n-i << '\n';
				isable = false;
			}
		}
		if(isable == true && n != 0 ) cout << "Goldbach's conjecture is wrong." << '\n';
	}
	
}
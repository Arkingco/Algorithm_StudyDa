#include<iostream>
#include<cmath>
using namespace std;

const int MAX_VALUE = 1000000;

bool eratose[MAX_VALUE + 1];
int main(){
	for(int i=2; i<=sqrt(MAX_VALUE); ++i){
		if(eratose[i] == true) continue;
		for(int j=i+i; j<=MAX_VALUE; j+=i){
			if(eratose[j] == false) eratose[j] = true;
		}
	}
	int  T, n , i;
	while(1){
		scanf("%d",&n);
		if(n == 0) break;
		i = 3;
		while(1){
			if( n - i < 0){
				printf("Goldbach's conjecture is wrong.\n");
				break;
			} 
			if(eratose[i] == false && eratose[n-i] == false ){
				cout << n <<" = " << i << " + " << n-i << '\n';
				break;
			}
			i++;
		}
		
	}
	return 0;
}
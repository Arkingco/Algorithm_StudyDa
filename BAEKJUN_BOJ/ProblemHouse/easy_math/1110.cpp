#include<iostream>
using namespace std;

int main(){
	
	int n,i=0 , sum = 0;
	cin >> n;
	sum = n;
	while(1){
		int a = (sum/10);
		int b = sum%10;
		sum = a+b;
		++i;
		sum = (b*10) + (sum % 10);
		if(sum == n) break;
		
	}
	cout << i;
}
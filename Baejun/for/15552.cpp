#include<iostream>
#include<stdio.h>

using namespace std;



int main(){
	
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;

	for(int i=0; i<n; ++i){
		int a , b;
		cin >> a >> b;
		printf("%d\n",a+b);
	}
}
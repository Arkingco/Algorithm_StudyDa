#include<iostream>
using namespace std;


int main(){
	int n;
	cin >>n;
	
	int i=0; int sum=0;
	while(sum + i < n-1)	
		sum += ++i;

	
	int val = n-sum;
	if( i % 2 != 0){
		cout <<val << "/"<< i+2-val << endl;
	} else {
		
		cout <<i+2-val << "/"<< val << endl; 
	}
	
	
}
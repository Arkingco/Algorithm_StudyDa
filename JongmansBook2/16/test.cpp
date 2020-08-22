#include<iostream>
using namespace std;

int main(){
	int n = 7;
	
	for(int i=n; i; i = ((i-1))){
		cout << i << "  ";
	}
}
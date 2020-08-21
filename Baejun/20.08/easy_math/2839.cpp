#include<iostream>
using namespace std;


int main(){
	int n;
	cin >> n;
	int val = 0;
	while(n > 0){
		if(n % 5 == 0 ){
			n -= 5;
			val++;
		}
		else if(n % 3 == 0 ){
			n -= 3;
			val++;
		}
		else if(n > 5){
			n -= 5;
			val++;
		}
		else {
			val = -1;
			break;
		}
	}
	cout << val;
}
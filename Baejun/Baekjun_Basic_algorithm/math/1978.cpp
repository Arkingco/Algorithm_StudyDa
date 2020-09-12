#include<iostream>
using namespace std;

bool era[1001];

int main(){
	era[1] = true;
	for(int i=2; i<=1000; ++i){
		for(int j=i; i*j<=1000; j++){
			era[i*j] = true;
		}
	}
	int T ,n , count = 0;
	cin >> T;
	while(T--){
		cin >>n;
		if(era[n] == false) count++;
	}
	cout << count << endl;
	
}
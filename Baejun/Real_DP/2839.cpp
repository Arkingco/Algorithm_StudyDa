#include<iostream>
using namespace std;

int topDown(int n){
	int a , b;
	if(n == 0) return 12321123121;
	if(n % 3 == 0)
		a = topDown(n/3) + n/3;
	else if(n % 2 == 0)
		b = topDown(n/2) + n/2;
	else{
		return -1;
	}
	return min(a , b);
}
int dp[5001];
int bottomUp(int n){
	
}
int main(){
	int n;
	cin >> n;
	cout << topDown(n) << endl;
}
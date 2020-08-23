#include<iostream>
using namespace std;

long long int dp[100] = {0,1,1};
long long int pibo(int n){
	
	if( n == 0 ) return 0;
	if( n <= 2) return 1;
	long long int& ret = dp[n];
	if(ret != 0) return ret;
	return ret = pibo(n-1) +  pibo(n-2);
}
int main(){
	int n;
	cin >> n;
	cout << pibo(n) << endl;
}
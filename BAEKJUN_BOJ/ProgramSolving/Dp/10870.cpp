#include<iostream>
using namespace std;

int cache[21];
int ki(int n){
	int& ret = cache[n];
	if(ret != 0) return ret;
	if(n == 1) return 1;
	if(n == 0) return 0;
	
	return ret = ki(n-1) + ki(n-2);
}
int main(){
	int n;
	cin >> n;
	cout << ki(n) << endl;
}
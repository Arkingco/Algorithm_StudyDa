#include<iostream>
using namespace std;
void back(int n){
	if(n == 0) return;
	int ret = back(n-1);
	cout << n << endl;
	return;
}
int main(){
	int n;
	cin >> n;
	cout << back(n) << endl;
}
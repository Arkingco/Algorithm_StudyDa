#include<iostream>
using namespace std;

int n;
int main(){
	int value;
	cin >> n >> value;
	for(int i=0; i<n; ++i){
		int val;
		cin >> val;
		if(val < value) printf("%d ",val);
	}
}
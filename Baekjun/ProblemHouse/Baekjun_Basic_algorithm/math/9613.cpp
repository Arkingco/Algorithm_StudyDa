#include<iostream>
using namespace std;

int gcd(int a, int b){
	while(b!=0){
		int r = a%b;
		a= b;
		b= r;
	}
	return a;
}

int main(){
	
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		long long int arr[101];
		long long int result = 0;
		for(int i=0; i<n; ++i){
			cin >> arr[i];
		}
			for(int i=0; i<n; ++i){
				for(int j=i+1; j<n; ++j){
				long long int a = max(arr[i],arr[j]);
				long long int b = min(arr[i],arr[j]);
				result = result + gcd(a , b);	
				}
			}
			cout << result << endl;
		}
		
		
}

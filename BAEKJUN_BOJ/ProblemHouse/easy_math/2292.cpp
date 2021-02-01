#include<iostream>
using namespace std;


//6의 배수 만큼 육각형 개수가 늘어남
// 1 -> 7 -> 19 -> 37 -> 61
// 1 + 6 + 12 + 18 + 24 순서
long long int a=1;
int main(){
	
	int n;
	cin >> n;
	for(int i=1; i<50000; ++i){
		if(n <= a){
			cout << i;
			break;
		}
		a = i*6 + a;
	}
}
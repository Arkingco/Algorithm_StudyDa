#include<iostream>
using namespace std;

int main(){
	
	int n,a , b ,c;
	
	cin >> n;
	while(n--){
		cin >> a >> b >> c;
		if(c%a != 0){
			cout <<(c%a *100) + ((c/a)+1) << endl;
		} else{
			cout << (100 * a) +  ((c/a)) << endl;
		}
		
	}

}
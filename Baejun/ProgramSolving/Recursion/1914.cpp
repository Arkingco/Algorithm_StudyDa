#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int n;
void move(int N , string start , string to){
	cout << start << " " << to << '\n';
}
void hanoi(int N , string start , string to , string via){
	if(N == 1)
		move(1 , start , to);
	else {
		hanoi(N-1 , start , via , to);
		move(N , start , to);
		hanoi(N-1 , via , to , start);
	}
}
int main(){

	cin >> n;
	string hanoi_n = to_string(pow(2,n));
	int index = hanoi_n.find('.');
	hanoi_n = hanoi_n.substr(0 , index);
	hanoi_n[hanoi_n.length() -1] -=1;
	cout << hanoi_n << endl;
	if(n <= 20){
		hanoi(n , "1" ,"3" , "2");
	}
	
}
#include<iostream>
#include<vector>
using namespace std;

/*
20
7
23
19
10
15
25
8
13
*/
const int Nanjangs = 9;
vector<int> brude(Nanjangs);

int force(int n){
	if(n == 9) return 0;
	if( force(n-1 ) + brude[n] == 100){
		cout << "find";
	} 
	if( force(n-1) == 100) {
		cout << "find 2";
	}
		
} 

int main(){

	for(int i=0; i<9; ++i){
		cin >> brude[i];
	}
	vector<int> list;
	force(0);
}
#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> faild(const string& N){
	int n = N.size();
	int begin = 1 , matched = 0;
	vector<int> pi (n,0);
	while(begin + matched < n){
		if(N[begin + matched] == N[matched] ){
			matched++;
			
			pi[begin+matched -1 ] = matched;
		}
		else {
			if(matched == 0 ) begin++;
			else {
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}
			
		}
	}
	
	return pi;
}
int KMP(const string& H , const string& N){
	int n = N.size() , h = H.size();
	int begin = 0 , matched = 0;
	vector<int> pi = faild(N);
	while(begin <= h-n){
		if(matched < n && H[begin + matched ] == N[matched]){
			matched++;
			
			if(matched == n ) return 1;
		}
		else {
			if(matched == 0 ) begin++;
			else{
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}
	
	return 0;
}
int main(){
	string a , b;
	cin >> a >> b;
	cout << KMP(a,b) << '\n';
}
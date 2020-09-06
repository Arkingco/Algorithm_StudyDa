#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> falid(const string& N){
	int n = N.size();
	int begin=1 , matched =0;
	vector<int> pi(n , 0);
	while(begin + matched < n){
		if(N[begin + matched ] == N[matched]){
			matched++;
			pi[begin + matched - 1 ] = matched;
		} else {
			if(matched==0) begin++;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched-1];
			}
		}
	}
	return pi;
}
int main(){
	int n;
	string a;
	cin >> n >> a;
	vector<int> ret = falid(a);
	cout <<  a.size()-ret[a.size()-1] << endl;
}
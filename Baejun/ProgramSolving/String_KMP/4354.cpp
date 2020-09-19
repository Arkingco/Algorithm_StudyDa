#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> faild(const string& N){
	int n = N.size();
	int begin = 1 , matched =0;
	vector<int> pi(n , 0);
	while(begin + matched < n){
		if(N[begin + matched] == N[matched]){
			matched++;
			pi[begin+matched - 1] = matched;
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
int main(){
	while(1){
		string a;
		cin >> a;
		if(a==".") break;
		vector<int> pi = faild(a);
		int len = pi.size();
		int ret = pi[len-1];
		if(len % (len - ret )) cout << 1 << '\n';
        else cout << len / (len - ret) << '\n';
	}
}
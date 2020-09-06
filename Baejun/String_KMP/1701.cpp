#include<iostream>
#include<vector>
#include<string>
using namespace std;

int falid(const string& N){
	int n = N.size();
	int begin = 1 , matched = 0;
	vector<int> pi(n,0);
	int maxpi = 0;
	while(begin + matched < n){
		if(N[begin + matched ] == N[matched]){
			matched++;
			pi[begin + matched - 1] = matched;
			maxpi = max(maxpi , matched);
		}
		else {
			if(matched == 0) begin++;
			else {
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}
	return maxpi;
}

int main(){
	string a;
	cin >> a;
	int maxi = 0;
	for(int i=0; i<a.size(); ++i){
		int ret = falid(a.substr(i));
		maxi = max(maxi , ret);
		
	}
	cout << maxi << '\n';
}
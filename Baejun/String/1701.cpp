#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> getfailed(const string& N){
	string M = N;
	int n = N.size();
	int begin = 1 , matched = 0;
	vector<int> pi(n , 0 );
	while(begin + matched < n ){
		if(M[begin+matched] == N[matched]){
			matched++;
			pi[begin+matched-1] = matched;
		} else {
			if(matched == 0) begin ++;
			else {
				// 여기서 pi[matched - 1] 은 아직 값이 0이니 결국 매치된 수 만큼 begin 값이 올라간다는 얘기임 즉 
				//M[1]은 같고 M[2]가 다르다면 KMP알고리즘에서는 pi[matched]만큼 스킵이 되지만 여기선 값이0이기 때문에
				// 값은 결국 M[2] 부터 시작하는 걸로 된다.
				begin += matched - pi[matched-1];
				// 아래도 마찬가지로 0 으로 되니 문제 없음
                matched = pi[matched-1];
			}
		}
		
	}
	return pi;
}

vector<int> KMP(const string& M , const string& N){
	int n = N.size() , m= M.size();
	// begin : 처음 비교할 자리 수 matched : 얼마나 비교 되었는지 확인하는 수
	int begin = 0 , matched = 0;
	// 완료 되었을 때 리턴 값.
	vector<int> ret;
	vector<int> pi = getfailed(N);
	while( begin <= m-n){
		// 비교할 인덱스가 N문자열의 범위를 넘어가지 아니하고
		// M[begin + matched(0)] 부터 시작해서 N과 비교 맞으면 한칸씩 matched를 늘려주기 
		if(matched < n && M[begin + matched] == N[matched]){
			matched++;
			
			if(matched == n) ret.push_back(begin);
		} else {
			if (matched == 0) begin++;
			else{
			begin += matched - pi[matched - 1];
			matched = pi[matched-1];	
			}
		}
	}
	return ret;
}

int main(){
	
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	
	string n;
	getline(cin ,n);
	
	int maxSize =0;
	for(int i=1; i<=n.size(); ++i){
		vector<int> ret = KMP(n,n.substr(0, i));
		int size = ret.size();
		maxSize = max(maxSize , size);
	}
	
	cout << maxSize << endl;
}


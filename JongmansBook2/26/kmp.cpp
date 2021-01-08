#include<iostream>
#include<vector>
#include<string>
using namespace std;

// N에서 자기 자신을 찾으면서 나타나는 부분 일치를 이용해
// pi[]를 계산한다.
// pi[i] = N[..i]의 접미사도 되고 접두사도 되는 문자열의 최대길이
vector<int> getPartialMatch(const string& N) {
	int m = N.size();
	vector<int> pi(m, 0);
	// KMP로 자기 자신을 찾는다.
	// N을 N에서 찾는다. begin = 0이면 자기 자신을 찾아버리니까 안됨!
	int begin = 1, matched = 0;
	// 비교할 문자가 N의 끝에 도달할 때까지 찾으면서 부분 일치를 모두 기록한다.
	while(begin + matched < m) {
		if(N[begin + matched] == N[matched]) {
			++matched;
			pi[begin+matched-1] = matched;
		}
		else {
			if(matched == 0) {
				++begin;
			} else {
				begin += matched - pi[matched - 1];
				matched = pi[matched];
			}
			
		}
	}
	return pi;
}

vector<int> getPartialMatchNaive(const string& N) {
	int m = N.size();
	vector<int> pi(m, 0);
	// 단순한 문자열 검색 알고리즘을 구현한다.
	for(int begin = 0; begin < m; ++begin) {
		for(int i=0; i+begin < m; ++i) {
			if(N[begin + i] != N[i]) break;
			pi[begin + i] = max(pi[begin + i], i + 1);
		}
	}
	return pi;
}

vector<int> kmpSearch(const string& H, const string& N) {
	int n = H.size();
	int m = N.size();
	vector<int> ret;
	// pi[i] = N[..i] 의 접미사도 되고 접두사도 되는 문자열의 최대 길이
	vector<int> pi = getPartialMatch(N);
	
	int begin = 0;
	int matched = 0;
	
	// ( H.size > N.size 일 때 남은 비교할 문자들의 수가 패턴 문자열보다 크거나 같다면 )
	while(begin <= n - m ) {
		// 만약 짚더미의 해당 글자가 바늘의 해당 글자와 같다면
		// default[matched == 0, max(m) == matched, begin == 지금 까지 [비교, 넘겨온] 시작점]
		if(matched < m && H[begin + matched] == N[matched]) {
			
			++matched;
			// 결과적으로 m글자가 모두 일치했으면 답에 추가한다.
			if(matched == m) ret.push_back(begin);
		} else {
			// 예외 : matched == 0 인경우 다음 칸에서 실행
			if(matched == 0) {
				begin++;
			} else {
				begin += matched - pi[matched-1];
				
				// begin 을 옮겻다고 해도 처음부터 다시 비교할 필요가 없다.
				// 옮긴 후에도 pi[matched - 1] 만큼은 항상 일치하기 때문이다.
				matched = pi[matched - 1];
			}
		}
	}
	return ret;
}

int main() {
	string S, T;
	cin >> S;
	vector<int> pi = getPartialMatch(S);
	
	for(int i=0; i<pi.size(); ++i) {
		cout << pi[i] << " ";
	}
}
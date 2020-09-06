#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> failure_function(const string& S)
{
    int n = S.length();
    vector<int> f(n,0);
    int begin = 1, m = 0;

    // 끝까지 확인한다.
    while(begin+m < n) {
        // 일치하면 m을 증가시키고 실패함수를 초기화한다.
        if(S[begin+m]==S[m]) {
            m++;
            f[begin+m-1] = m;
        }
        else {
            if(m==0)
                begin++;
            else {
                begin += (m - f[m-1]);
                m = f[m-1];
            }
        }
    }
    return f;
}

vector<int> kmp(const string& H, const string& S) 
{
    int h_len = H.length();
    int s_len = S.length();

    // 실패 함수값을 구해놓았다는 가정.
    vector<int> f = failure_function(S);
    vector<int> r(h_len-s_len+1,0);

    int begin = 0, m = 0;
    while(begin <= h_len-s_len) {
        // 일치개수(m)가 S의 길이보다 작고
        // H[begin+m]과의 문자가 일치하는 경우
        if(m<s_len && H[begin+m]==S[m]){
            m++;
            // S를 찾은 경우에 begin값을 저장한다.
            if(m == s_len) r.push_back(begin);
        }
        // 불일치하거나 S를 찾은 경우
        else {
            // 일치한적이 한번도 없고 불일치했다면 단순히 begin 옮기면 된다.
            if(m==0)
                begin++;
            // 그게 아니라면 begin과 m을 위에서 말한 것처럼 초기화!
            else {
                begin += (m - f[m-1]);
                m = f[m-1];
            }
        }
    }
    return r;
}

int main(){
	string n , h;
	char c[1000001];
	cin.getline(c , 1000001);
	n = c;
	cin >> h;
	
	vector<int> ret = kmp(n,h);
	cout << ret.size() << endl;
	for(int i=0; i<ret.size(); ++i){
		cout << ret[i] << endl;
	}
}
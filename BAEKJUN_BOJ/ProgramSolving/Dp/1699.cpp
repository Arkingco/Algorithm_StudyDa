#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int memo[1000001]; // -> -1;

//// TopDown 하지만 스택오버플로 남 방식의 한계?
// int dp(int valueN) {
//     if (valueN < 0) return 10000000;

//     if (valueN == 0) return 0;

//     if (memo[valueN] != -1) return memo[valueN];
//     int ret = 10000000;

//     for (int i = 1; i<=int(sqrt(round(valueN))); ++i) {
//         ret = min(ret, dp(valueN - i * i) + 1);
//     }
//     cout << ret << endl;
//     return memo[valueN] = ret;
// }

// c++ 기본 문법에서 행하는 (int) 명령어는 기본적으로 반올림이 아니라 캐스팅 이기 때문에 3.99999의 값을 (int)로 묶어준다면 0.99999를 뺀 3만 출력해준다.
int main() {

    // 0 < N < 1000000
    int n;
    cin >> n;

    memset(memo, 0, sizeof memo);

    memo[0] = 0;
    for(int i=1; i<= n; ++i) {
        memo[i] = i;

        for(int j= 1; j*j <= i; ++j) {
            memo[i] = min(memo[i], memo[i-j*j]+1);
        }
    }

    cout <<memo[n] << endl;
    
}
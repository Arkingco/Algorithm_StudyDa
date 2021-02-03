#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> dp(n, 1);
    vector<int> anser(n);
    for(int i=0; i<n; ++i) {
        cin >> anser[i];

    } 
    int ret = 0;
    for(int i=0; i<n; ++i) {
        
        for(int j=i; j<n; ++j) {
            if(anser[i] < anser[j] && dp[i] == dp[j]) {
                dp[j] = dp[j]+1;
                ret = max(ret, dp[j]);
            }
                   
        }
    }

    cout << ret << endl;
}

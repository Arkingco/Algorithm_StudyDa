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

    for(int k=0;  k<n; ++k) {
        dp[k] = 1;
        for(int i=0; i<k; ++i) {
            if(arr[i] < arr[k]) {
                length[k] = max(length[k], length[i] + 1;
            }
        }
    }
    cout << ret << endl;

}
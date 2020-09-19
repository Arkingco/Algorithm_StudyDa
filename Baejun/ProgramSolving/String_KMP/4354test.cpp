#include<iostream>
#include<vector>
#include<cstring>
#include<string>
using namespace std;

 
int fail[1000000];
 
int main() {
    string S;
    int slen;
    while (1) {
        cin >> S;
        if (S == ".") break;
        slen = S.size();
        memset(fail, 0, sizeof(fail));
 
        for (int i = 1, j = 0;i < slen;++i) {
            while (j && S[i] != S[j]) j = fail[j - 1];
            if (S[i] == S[j]) fail[i] = ++j;
        }
        if (slen % (slen - fail[slen - 1])) cout << 1 << '\n';
        else cout << slen / (slen - fail[slen - 1]) << '\n';
    }
 
    return 0;
}
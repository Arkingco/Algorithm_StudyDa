#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    char a[101];
    cin >> a;

    int ret = 0;
    for (int i = 0; i < n; ++i) {
        ret += a[i] - '0';
    }

    cout << ret << '\n';
}
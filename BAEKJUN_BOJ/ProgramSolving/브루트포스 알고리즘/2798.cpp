#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
using namespace std;

int main() {

	int value[101];
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		cin >> value[i];
	}

	int ret = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = i+1; j < N; ++j) {
			for (int z = j+1; z < N; ++z) {
				int check = value[i] + value[j] + value[z];
				if (check <= M) {
					ret = max(ret, value[i] + value[j] + value[z]);
				}
			}
		}
	}

	cout << ret << '\n';
}
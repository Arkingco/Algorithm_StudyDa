#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
using namespace std;

int main() {
	
	string croatia[8] = { "c=", "c-", "dz=","d-", "lj", "nj", "s=", "z=" };

	string S;
	cin >> S;
	
	
	int ret = 0;
	for (int i = 0; i < S.size(); ++i) {
		
		int findString = -1;
		for (int j = 0; j < 8; ++j) {
			// s[i] 에서부터 croatia[j].size()만큼 substr을 돌려서 나오면 반환한다.
			if (findString == -1) {
				if (S.size() >= croatia[j].size() && strcmp(S.substr(i, croatia[j].size()).c_str(), croatia[j].c_str()) == 0) {
					findString = j;
					break;
				}
			}
		}

		if (findString != -1) {
			S.replace(i, croatia[findString].size(), "0");
			ret++;
		}
		else {
			S.replace(i, 1, "0");
			ret++;
		}
		
	}

	cout << ret << '\n';
}
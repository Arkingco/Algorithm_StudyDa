#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

const int SQURD_MAP_MAX_SIZE = 4;
int squrd_map[SQURD_MAP_MAX_SIZE+1] = {0, 1, 4, 2, 3};

vector<int> wordList;
int maxCrossSize = 0;
int findWord(int word) {
	for(int i=0; i<wordList.size(); ++i) {
		if(word == wordList[i]) {
			wordList.erase(wordList.begin() + i);
			
			int ret = wordList.size()-i;
			maxCrossSize = max(maxCrossSize, ret+1);
			return ret;
		}
	}
	
	return -1;
}

int main() {
	
	int map[51][51] = { 0, };
	
	int n;
	cin >> n;
	
	for(int i=1; i<=n/2; ++i) {
		for(int j=0; j<2; ++j) {
			int a, b;
			cin >> a >> b;
			
			map[a][b] = i;
		}
		
	}
	

	// 입력부
	vector<int> list;
	for(int i=1; i<=4; ++i) {
		if(squrd_map[i]==2 || squrd_map[i] == 3) {
			for(int j=n; j>=0; --j) {
				if(map[squrd_map[i]][j] != 0 ) list.push_back(map[squrd_map[i]][j]);
			}
		} else {
			for(int j=0; j<n; ++j) {
				if(map[squrd_map[i]][j] != 0 ) list.push_back(map[squrd_map[i]][j]);
			}
		}
		for(int z=0; z<list.size(); ++z) {
		}
	}
	
	
	int ret = 0;
	for(int i=0; i<list.size()-1; ++i) {
		if(list[i] != list[i+1]) {
			
			int checkWord = findWord(list[i]);
			if(checkWord != -1) {
				ret = ret + checkWord;
			} 
			else {
				wordList.push_back(list[i]);
			}
			
		} else {
			i++;
		}
	}
	cout << ret << endl;
	cout << maxCrossSize << endl;
}
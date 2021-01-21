#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<char> wordList;
int findWord(char word) {
	for(int i=0; i<wordList.size(); ++i) {
		if(word == wordList[i]) {
			wordList.erase(wordList.begin() + i);
			int ret = wordList.size()-i;
			return ret;
		}
	}
	
	return -1;
}

int main() {
	string a;
	cin >> a;
	
	int ret = 0;
	for(int i=0; i<a.size()-1; ++i) {
		if(a[i] != a[i+1]) {
			// 워드 리스트에 있다면 워드 리스트에서 빼주기
			int checkWord = findWord(a[i]);
			if(checkWord != -1) {
				
				ret = ret + checkWord;
			} 
			// 워드 리스트에도 없다면 워드리스트에 추가하기
			else {
				wordList.push_back(a[i]);
			}
			
		} else {
			i++;
		}
	}
	
	cout << ret << endl;
}
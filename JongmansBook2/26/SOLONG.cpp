#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

const int ALPABET = 26;

int charToNumber(char ch) { return 'A'-ch;}

struct Trie {
	
	bool isEndWord;
	Trie* children[ALPABET];
	int HighProirityID;
	
	Trie() : isEndWord(false), HighProirityID(0) {
		memset(children, 0, sizeof(children));
	}

	~Trie() {
		for(int i=0; i<ALPABET; ++i) {
			if(children[i] != NULL) {
				delete children[i];
			}
		}
	}
	
	void insert(const char* key, int id) {

		if(*key == 0) {
			isEndWord = true;
		} else {
			
			if(HighProirityID <= id) {
				HighProirityID = id;
			}
			
			int next = charToNumber(*key);
			
			if(children[next] == NULL) {
				children[next] = new Trie();
			}
			
			children[next]->insert(key + 1, HighProirityID);
		}
	}
	
	bool find(const char* key) {
		if(*key == 0 ) {
			return true;
		}
		
		int next = charToNumber(*key);
		if(children[next] == 0) {
			return false;
		}
		
		return children[next] -> find(key+1);
	}
	
};

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n, m;
		cin >> n >> m;
		
		Trie* trie = new Trie();
		vector<string> wordList;
		
		
		for(int i=0; i<n; ++i) {
			string Trieword;
			int wordPriority;
			
			cin >> Trieword >> wordPriority;	
			trie->insert(Trieword.c_str(), wordPriority);
		}
		
		for(int i=0; i<m; ++i) {
			string word;
			cin >> word;
			wordList.push_back(word);
		}
		
		int ret = 0;
		for(int i=0; i<wordList.size(); ++i) {
			
		}
		
	}
}
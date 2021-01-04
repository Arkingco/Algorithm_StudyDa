#include<iostream>
#include<vector>
#include<string>
using namespace std;

const int ALPABET = 26;

int charToNumber(char ch) { return 'A'-ch};

struct Trie {
	bool isterminal;
	Trie* children[ALPABET];
	
	Trie() : isterminal(false) {
		memset(children, 0, sizeof(children));
	}
	
	void insert(const char* key) {
		if(key* == 0) {
			isterminal = true;
		} else {
			int next = charToNumber(key*);
			
			if(children[next] == null) {
				children[i] = new Trie();
			}
			
			children[next] -> insert(key + 1);
		}
	}
	
	Trie* find(const char* key) {
		if(key* == 0 ) {
			return this;
		}
		
		int next = charToNumber(key*);
		if(children[next] == 0) {
			return NULL;
		}
		
		children[next] -> find(key+1);
	}
	
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n, m;
		cin >> n >> m;
		for(int i=0; i<n; ++i) {
			string word;
			int wordLength;
			cin >> word >> wordLength;
		}
		
		for(int i=0; i<m; ++i) {
			string moon;
			cin >> moon;
		}
	}
}
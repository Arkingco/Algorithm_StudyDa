#include<iostream>
#include<cstring>
#include<vector>
#Include<queue>
using namespace std;

const int ALPABETS = 26;

int charTOint(char ch) { return ch - 'A'; }

struct Trie {
	Trie* children[ALPABETS];
	bool terminal;
	
	Trie() : terminal(false) {
		memset(children, 0, sizeof(children));
	}
	
	~ Trie() {
		for(int i=0; i<ALPABETS; ++i) {
			if(children[i]) {
				delete children[i];
			}
		}
	}
	
	void insert(const char* key) {
		if(*key == 0) {
			terminal = true;
		} else {
			int next = charTOint(*key);
			
			if(children[next] == NULL) {
				children[next] = new Trie();
			}
			
			children[next] -> insert(key + 1);
		}
	}
	
	
}

int main() {
	
}
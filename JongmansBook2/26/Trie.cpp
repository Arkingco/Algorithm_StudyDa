#include<iostream>
#include<cstring>
using namespace std;

const int ALPHABETS = 26;

int char_to_index(char c) {
	return c-'A';
}

struct Trie {
	
	bool is_terminal;
	Trie* children[ALPHABETS];
	
	Trie() : is_terminal(false) {
		memset(children, 0, sizeof(children));
	}
	
	~Trie() {
		for(int i=0; i<ALPHABETS; ++i) {
			if(children[i])
				delete children[i];
		}
	}
	
	void insert(const char* key) {
		if(*key == '\0') {
			is_terminal = true;
		}
		else {
			int index = char_to_index(*key);
			
			if(children[index] == 0)
				children[index] = new Trie();
			children[index] -> insert(key+1);
		}
	}
	
	Trie* find(const char* key) {
		if(*key == 0) {
			return this;
		}
		
		int index = char_to_index(*key);
		if(children[index] == 0) {
			return NULL;
		}
		
		return children[index] -> find(key+1);
	}
	
	bool string_exist(const char* key) {
		if(*key == 0 && is_terminal) {
			return true;
		}
		
		int index = char_to_index(*key);
		if(children[index] == 0 ) {
			return false;
		}
		
		return children[index] -> string_exist(key+1);
	}
}

int main() {
	
}




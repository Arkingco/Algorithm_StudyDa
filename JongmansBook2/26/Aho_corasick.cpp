#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

const int ALPABETS = 26;

int charTOint(char ch) { return ch - 'A'; }

// trie에 포함된 패턴들을 s에서 찾는다.
// s내에서 패턴이 출현할 때마다 (마지막 글자, 패턴 번호)의 쌍을 저장한다.
vector<pair<int, int> > ahoCorasick(const string& s, Trie* root) {
	vecto<pair <int , int > > ret;
	Trie* state = root;
	
	// 실재 반복문 내는 KMP와 별로 다를 것이 없다.
	for(int i=0; i<s.size(); ++i) {
		int chr = charTOint(s[i]);
		while(state != root && state)
	}
}

// 트라이가 주어질 때 각 노드에 대해 실패 연결과 출력 문자열 목록을 계산한다.
void computeFailFunc(Trie* root) {
	// 루트에서부터 시작해 한 단계씩 아래로 내ㅑ려가며 각 노드의 실패 연결을 계산한다.
	queue<Trie*> q;
	// 루투의 실패 연결은 자기 자신
	root->fail = root;
	q.push(root);
	
	while(!q.empty()) {
		Trie* here = q.front();
		q.pop();
		
		// here의 모든 자손에 대해 실패 연결을 계산하고 이들을 큐에 넣는다.
		for(int edge = 0; edge<ALPABETS; ++edge) {
			Trie* child = here->children[edge];
			
			if(!child) continue;
			
			// 1레벨 노드의 실패 연결은 항상 루트
			if(here = root) {
				here->fail = root;
			} else {
				// 아닌 경우 부모의 실패 연결능 따라가면서 실패 연결을 찾는다.
				Trie* t = here->fail;
				while(t != root && t->children[edge] == NULL) {
					t = t->fail;
				}
				if(t-> children[edge]) t = t->children[edge];
				child => fail = t;
				// 이 위치에서 끝나는 바늘 문자열이 있으면 추가한다.
				child -> output = child->fail->output;
				if(child->terminal != -1) {
					child->output.push_back(child->terminal);
				}
				q.push(child);
			}
		}
	}
}


struct Trie {
	Trie* children[ALPABETS];
	int terminal;
	Trie* fail;
	vector<int> output;
	
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
			terminal = 1;
		} else {
			int next = charTOint(*key);
			
			if(children[next] == NULL) {
				children[next] = new Trie();
			}
			
			children[next] -> insert(key + 1);
		}
	}
	
	Trie* find(const char* key) {
		if(*key == 0 && terminal == 1) {
			return this;
		} else {
			int next = charTOint(*key);
			
			if(children[next] == NULL) 
				return NULL;
			
			return children[next] -> find(key + 1);
		}
	}
};

int main() {
	
	int n;
	cin >> n;
	Trie* trie = new Trie();
	for(int i=0; i<n; ++i) {
		string a;
		cin >> a;
		trie->insert(a.c_str());
	}
	
}






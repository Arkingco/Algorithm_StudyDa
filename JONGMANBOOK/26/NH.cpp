#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

const int ALPABET = 26;
const int MOD = 10007;
int charToint(char ch) { return ch - 'A';}

void getLog(char a) {
	cout <<  a << endl;
}

struct Trie {
	
	Trie* children[ALPABET];
	Trie* fail;
	int terminal;
	vector<int> output;
	
	Trie() : terminal(-1) {
		memset(children, 0, sizeof(children));
	}
	
	~Trie() {
		for(int i=0; i<ALPABET; ++i) {
			if(children[i]) {
				delete children[i];
			}
		}
	}
	
	void insert(const char* key, int id) {
		if(*key == 0) {
			terminal = id;
		} else {
			int next = charToint(*key);
			
			if(!children[next]) {
				children[next] = new Trie();
			}
			
			return children[next] -> insert(key + 1, id);
		}
	}
	
	Trie* find(const char* key, int id) {
		if(*key == 0) {
			return this;
		} else {
			int next = charToint(*key);
			
			if(children[next] == NULL) {
				return NULL;
			}
			
			return children[next] -> find(key+1, id);
		}
		
	}
	
};

// 트라이가 주어질 때 각 노드에 대해 실패 연결과 출력 문자열 목록을 계산한다.
void computeFailFunc(Trie* root) {
	queue<Trie*> q;
	root -> fail = root;
	q.push(root);
	
	while(!q.empty()) {
		Trie* here = q.front();
		q.pop();
		
		for(int edge=0; edge<ALPABET; ++edge) {
			Trie* child = here->children[edge];
			
			if(!child) {
				continue;
			}
			
			if(here == root) {
				child -> fail = root;
			} else {
				Trie* t = here->fail;
				while(t != root && t->children[edge] == NULL) {
					t = t->fail;
				}
				if(t -> children[edge]) t = t -> children[edge];
				child -> fail = t;
			}
			
			// 실패함수의 문자열은 무조건 탐색이 되기 때문에 child에 추가해 준다.
			child->output = child->fail->output;
			if(child -> terminal != -1) {
				child->output.push_back(child->terminal);
			}
			q.push(child);
		}
	}	
}

vector<pair<int, int> > SeachTrie(const string& s, Trie* root) {
	vector<pair<int, int> > ret;
	Trie* state = root;
	
	// 실제 반복문 내는 KMP와 다를 것이 없다.
	for(int i=0; i< s.size(); ++i ) {
		int chr = charToint(s[i]);
		
		// 조건부 발생
		while(state != root && state -> children[chr] == NULL ) {
			if(state -> fail == NULL ) break;
			state = state->fail;
		}
		// 조건부 발생
		if(state -> children[chr]) state = state->children[chr];
		// 조건부 발생
		for(int j=0; j<state->output.size(); ++j ) {
			ret.push_back({i, state->output[j]});
		}
		
	}
	return ret;
}

int cache[101][1001];

// 앞으로 length 글자를 더 만들어야 하는데, 아호-코라식 알고리즘의
// 현재 상태가 state에 주어질 때 IDS에 걸리지 앟는 문자열의 수는?
int count(int length, Trie* state) {
	// 기저 사례:이 상태에 문자열이 출현하면 곧장 종료
	if(state -> output.size()) return 0;
	// 기저 사례 : 문자열을 전부 만든 경우
	if(length == 0) return 1;
	int& ret = cache[length][state->no];
	if(ret != -1) return ret;
	ret = 0;
	
	// 다음으로 letter 글자를 넣을 경우
	for(int letter = 0; letter < ALPABET; ++letter) {
		ret += count(length-1, state -> next[letter]);
		ret %= MOD;
	}
	return ret;
}

int main() {
	int n;
	cin >> n;
	
	Trie* root = new Trie();
	
	for(int i=0; i<n; ++i) {
		string a;
		cin >> a;
	
		root->insert(a.c_str(), i+1);
	}
	
	computeFailFunc(root);
	
	string sentance;
	cin >> sentance;

	vector<pair<int, int> > ret = SeachTrie(sentance, root);
	
	for(int i=0; i<ret.size(); ++i) {
		cout << ret[i].first << " " << ret[i].second << endl;
	}
}




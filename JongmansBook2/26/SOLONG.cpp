#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

const int ALPABET = 26;

int charToNumber(char ch) { return ch - 'A';}

struct Trie {
	
	int terminal;
	int first;
	Trie* children[ALPABET];
	
	Trie() : terminal(-1), first(-1) {
		memset(children, 0, sizeof(children));
	}

	~Trie() {
		for(int i=0; i<ALPABET; ++i) {
			if(children[i] != NULL) {
				delete children[i];
			}
		}
	}
	
	// 이 노드를 루트로 하는 트라이에 번호 id인 문자열 key를 추가한다.
	void insert(const char* key, int id) {
		// first 를 우선 갱신
		if(first == -1) first = id;
		// 문자열이 끝낫다면 terminal만 바꾸고 종료
		if(*key == 0)
			terminal = id;
		else {
			int next = charToNumber(*key);
			
			// 해당 자식 노드가 없다면 생성한다.
			if(children[next] == NULL) {
				children[next] = new Trie();
			}
			// 해당 자식 노드로 재귀 호출
			children[next] -> insert(key + 1, id);
		}
	}
	
	// 이 노드까지 타이핑해 왔을 때, 번호 id인 key를 타이핑 하기 위해
	// 최소 몇번의 키를 더 눌러야 하나?
	int type(const char* key, int id) {
		// 문자열 종료시
		if(*key == 0) return 0;
		// 이 노드에서 추천되는 문자열이 이 문자열이면 탭 누르고 종료
		if(first == id) return 1;
		// 아니면 다음 문자를 타이핑 한다.
		int next = charToNumber(*key);
		return 1 + children[next] -> type(key+1, id);
	}
	
	// 사진을 나타내는 트라이가 주어질 때, 단어 word를 타이핑하는 데
	// 몇 번이나 키를 눌러야 하는지 계산한다.
	int CountKeys(Trie* trie, const char* word) {
		// 이 문자열이 사전에 있는지 확인하고, 있다면 번호를 구한다.
		Trie* node = trie->find(word);
		// 사전에 없으면 직접 타이핑 할 수밖에 없다.
		if(node == NULL && node->terminal == -1) return strlen(word);
		cout << word << endl;
		return trie->type(word, node->terminal);
	}
	
	Trie* find(const char* key) {
		if(key == 0) 
			return this;
		int next = charToNumber(*key);
		if(children[next] == NULL) {
			return NULL;
		}
		return children[next] -> find(key + 1);
	}
};

// 입력에 주어지는 단어들을 정렬해서 트라이로 변환한다.
Trie* readInput(int words) {
	// 단어들을 출현 빈도의 내림차순, 단어의 오름차순으로 정렬한다.
	vector<pair<int, string> > input;
	for(int i=0; i<words; ++i) {
		char buf[11];
		int freq;
		scanf("%s %d", buf, &freq);
		input.push_back({-freq, buf});
	}
	sort(input.begin(), input.end());
	
	// 이때 앞에 있는 단어일수록 우선순위가 높다.
	// 배열의 인덱스를 각 단어의 번호로 쓰자.
	Trie* trie = new Trie();
	for(int i=0; i<input.size(); ++i) {
		trie->insert(input[i].second.c_str(), i);		
	}
	trie->first = -1;
	return trie;
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n, m;
		cin >> n >> m;
				
		Trie* trie = readInput(n);
		
		int ret = 0;
		for(int i=0; i<m; ++i) {
			string word;
			cin >> word;
			ret += trie -> CountKeys(trie, word.c_str());
			cout << ret << endl;
		}
		
		
	}
}
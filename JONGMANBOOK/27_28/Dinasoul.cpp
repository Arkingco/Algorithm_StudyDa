#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

const int MAX_VALUE = 26;
int T , n;
vector<vector<int> > value_graph;
bool visited[MAX_VALUE+1];
vector<int> V;
void make_value_graph(vector<string>& input){
	value_graph = vector<vector<int> >(26, vector<int>(26, 0));
	for(int i=1; i<input.size(); ++i){
		int j = i-1; 
		int forLength = min(input[i].size() , input[j].size());
		for(int k=0; k < forLength; ++k ){
			if(input[j][k] != input[i][k]){
				int a = input[j][k] - 'a';
				int b = input[i][k] - 'a';
				value_graph[a][b] = 1;
				cout << a << " " << b << endl;
				break;
			}
		}
	}
}

void dfs(int here){
	visited[here] = 1;
	for(int i=0; i<value_graph.size(); ++i){
		if(visited[i] == 0 && value_graph[here][i] == 1){
			cout << here << " " << i << "in " << endl;
			dfs(i);
		}
			
	}
	V.push_back(here);
}

vector<int> constribut(){
	
	for(int i=0; i<MAX_VALUE; ++i) if(visited[i] == 0) dfs(i);
	
	reverse(V.begin() , V.end());
	
	for(int i=0; i<MAX_VALUE; ++i){
		for(int k=i+1; k<MAX_VALUE; ++i){
			if(value_graph[V[i]][V[k]] == 1)
				return vector<int>();
		}
	}
	return V;
}

int main(){
	
	cin >> T;
	while(T--){
		cin >> n;
		vector<string> input;
		
		while(n--){
			string a;
			cin >> a;
			input.push_back(a);
		}
		make_value_graph(input);
		vector<int> ae = constribut();
		
		for(int i=0 ; i<ae.size(); ++i){
			cout << ae[i] << " ";
		}
		
	}
	
}
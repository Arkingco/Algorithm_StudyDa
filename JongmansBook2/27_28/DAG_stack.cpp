#include<iostream>
#include<vector>
#include<stack>
using namespace std;
#define MAX_SIZE 10
 
vector<int> edge[MAX_SIZE];
int visit[MAX_SIZE];
stack<int> st;
 
void dfs(int v) {
 
    for (int i = 0; i < edge[v].size(); i++) {
        int next_v = edge[v][i];
        if (visit[next_v] == 0) {
            visit[next_v] = 1;
            dfs(next_v);
        }
    }
    st.push(v);
}
 
int main(void) {
 
    int n, m;//정점 갯수, 간선 갯수
    
    cin >> n >> m;
 
    int a, b;//a가 b보다 먼저 실행되는 일
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        edge[a].push_back(b);
    }
 
    for (int i = 1; i <= n; i++) {
        if (visit[i] == 0) {
            visit[i] = 1;
            dfs(i);
        }
    }
 
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
 
    return 0;
}
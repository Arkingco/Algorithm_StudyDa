#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> seen, order;

void makeGraph(const vector<string>& words){
    adj = vector<vector<int>>(26, vector<int>(26,0));
    for(int j=1;j<words.size();j++){
        int i=j-1, len = min(words[i].size(), words[j].size());
        //word[j]가 word[i] 앞에 오는 이유를 찾는다.
        for(int k=0;k<len;k++)
            if(words[i][k] != words[j][k]){
                int a = words[i][k] - 'a';
                int b = words[j][k] - 'a';
                adj[a][b] = 1;
                break;
            }
    }
}

void dfs(int here){
    seen[here] = 1;
    for(int there=0;there<adj.size();there++)
        if(adj[here][there] && !seen[there])
            dfs(there);
    order.push_back(here);
}

//adj에 주어진 그래프를 위상정렬한 결과를 반환한다.
//그래프가 DAG가 아니라면 빈 벡터를 반환한다.
vector<int> topologicalSort(){
    int n = adj.size();
    seen = vector<int>(n,0);
    order.clear();
    for(int i=0;i<n;i++)
        if(!seen[i]) dfs(i);
    reverse(order.begin(), order.end());

    //만약 그래프가 DAG가 아니라면 정렬 결과에 역방향 간선이 있다.
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(adj[order[j]][order[i]])
                return vector<int>();
    //없는 경우라면 깊이 우선 탐색에서 얻은 순서를 반환한다.
    return order;
}

int main( ) {
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<string> words = vector<string>(N);
        for(int i=0;i<N;i++)
            cin >> words[i];
        makeGraph(words);
        vector<int> result = topologicalSort();
        if(result.empty())
            cout << "INVALID HYPOTHESIS" << endl;
        else{
            for(int i=0;i<result.size();i++)
                cout<<(char)(result[i]+'a');
            cout<<endl;
        }
    }
    return 0;
}
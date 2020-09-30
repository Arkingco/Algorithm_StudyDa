#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_NUM 100001
int V, E, counter=0, discovered[MAX_NUM];
bool isCutVertex[MAX_NUM];
vector<int> graph[MAX_NUM];
vector<pair<int, int> > edge;
 
int dfs(int A, int parent){
    discovered[A]= ++counter;
    int ret = discovered[A];
     
    for(int i = 0 ;  i< (int)graph[A].size() ; i++){
        int next = graph[A][i];
         
        if(next == parent)
            continue;
         
        if(!discovered[next]){
            //low : 정점 A의 자식 노드가 갈 수 있는 노드중 가장 일찍 방문한 노드
            int low = dfs(next, A);
            if(low > discovered[A]){
                edge.push_back(make_pair(min(A, next), max(A,next)));
            }
            ret=  min(ret, low);
        }else{
            ret = min(ret, discovered[next]);
        }
    }
    return ret;
}
 
int main(){
    cin >> V >> E;
    for(int i =1 ; i<= E; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
 
    dfs(1, 0);
     
    sort(edge.begin(), edge.end());
    printf("%d\n", (int)edge.size());
    for(int i = 0 ; i < edge.size() ; i++)
        printf("%d %d\n", edge[i].first, edge[i].second);
     
    return 0;
}
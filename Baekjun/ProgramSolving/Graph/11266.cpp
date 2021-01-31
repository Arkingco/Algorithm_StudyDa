#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_NUM 100010
using namespace std;

int V, E, counter=0; 
vector<bool>isCutVertex;
vector<int> discovered;
vector<vector<int> > graph;
 
int findCutVertex(int here , bool isRoot){
    discovered[here] = ++counter;
    int ret = discovered[here];
    
	int childNode = 0;
    for(int i = 0;  i< graph[here].size(); i++){
        int next = graph[here][i];
		
        if(discovered[next] == -1){
			childNode++;
            int low = findCutVertex(next, false);
            if(!isRoot && low >= discovered[here]){
            	isCutVertex[here] = true;
            }
            ret = min(ret, low);
        }else{
            ret = min(ret, discovered[next]);
        }
    }
	// 이 childNode라는건 discovered[here] 보다 더 높은 정점과 역방향 간선으로 연결되어 있지 않아서 생기는 조건임 2개이상일 때
	if(isRoot) isCutVertex[here] = (childNode >= 2);
    return ret;
}
 
int main(){
    cin >> V >> E;
	isCutVertex = vector<bool>(V+1 , false);
	graph = vector<vector<int> >(V+1 , vector<int>(0 , 0));
	discovered = vector<int>(V+1 , -1);
    for(int i =1; i<=E; i++){	
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
	
 	for(int i = 1; i <= V; i++){
        if(discovered[i] == -1)
            findCutVertex(i, true);
    }

    int cnt=0;
    for(int i = 1 ; i<= V; i++){
        if(isCutVertex[i])
            cnt++;
    }
    printf("%d\n", cnt);
    for(int i =1 ; i<= V; i++){
        if(isCutVertex[i])
            printf("%d ", i);
    }
	
    
     
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

int T, X , Y ,K;
vector<int> list_size;
vector<vector<int > > graph;
vector<vector< bool> >visited;
int graph_locations_X[4] = {
	0 , 1,  0, -1 
};
int graph_locations_Y[4] ={
	1 , 0 , -1 , 0
};
bool isCan(int x , int y , int i){
	if( x >=0 && y >= 0){
		if(visited[x][y] == false ){
			if( graph[x][y] == 1 ){
			return true;
			}
		}
	}
	return false;
}
int dfs(int here_x , int here_y){
	visited[here_x][here_y] = true;
	for(int i=0; i<4; ++i){
		int next_x = here_x + graph_locations_X[i];
		int next_y = here_y + graph_locations_Y[i];
		if(isCan(next_x ,next_y , i)){
			dfs(next_x,next_y);
		}
	}
	return 1;
}
int main(){
	cin >> T;
	while(T--){
		cin >> X >> Y >> K;
		graph = vector<vector<int> >(X+1 , vector<int>(Y+1,0));
		visited = vector<vector< bool> > (X+1 , vector<bool>(Y+1 , false));
		list_size = vector<int>(0,0);
		for(int i=0; i<K; ++i){
			int a , b;
			cin >> a >> b;
			graph[a][b] = 1;
		}
		
		// list_size() 가 컴포넌트의 개수
		for(int x = 0; x<X; ++x){
			for(int y=0; y<Y; ++y){
				if(visited[x][y] == false && graph[x][y] == 1)list_size.push_back(dfs(x , y));
			}
		}
		cout << list_size.size() << '\n';
	}
}
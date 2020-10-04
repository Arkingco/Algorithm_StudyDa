#include<iostream>
#include<vector>
using namespace std;

int N , X , Y;
vector<int> list_size;
vector<vector<int > > graph;
vector<vector< bool> >visited;
int graph_locations_X[4] = {
	0 , 1,  0, -1 
};
int graph_locations_Y[4] ={
	1 , 0 , -1 , 0
};
bool isCan(int x , int y , int i , int Precipitation){
	if( x >=0 && y >= 0){
		if(visited[x][y] == false ){
			if( graph[x][y] > Precipitation ){
			return true;
			}
		}
	}
	return false;
}
int dfs(int here_x , int here_y , int Precipitation){
	visited[here_x][here_y] = true;
	for(int i=0; i<4; ++i){
		int next_x = here_x + graph_locations_X[i];
		int next_y = here_y + graph_locations_Y[i];
		if(isCan(next_x ,next_y , i , Precipitation)){
			dfs(next_x,next_y , Precipitation);
		}
	}
	return 1;
}
int main(){
	cin >> N;
	graph = vector<vector<int> >(N+1 , vector<int>(N+1,0));
	int minimum = 987654321;
	int maximum = 0;
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j){
			cin >> graph[i][j];
			minimum = min(minimum , graph[i][j]);
			maximum = max(maximum , graph[i][j]);
		}
	}
	// 강수량
	int Precipitation = 0;
	int result = 0;
	for(int i=minimum; i<=maximum; ++i){
		visited = vector<vector< bool> > (N+1 , vector<bool>(N+1 , false));
		list_size = vector<int>(0,0);
		Precipitation = i;
		for(int x = 0; x<N; ++x){
			for(int y=0; y<N; ++y){
				if(visited[x][y] == false && graph[x][y] > Precipitation)list_size.push_back(dfs(x , y ,Precipitation));
			}
		}
		result = max(result , (int)list_size.size());
	}
	cout << result << '\n';
	
	return 0;
}
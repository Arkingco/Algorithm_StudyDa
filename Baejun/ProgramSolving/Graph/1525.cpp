#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<string>
using namespace std;
int dx[] = {0 , 0 , 1 , -1};
int dy[] = {1 , -1 , 0 , 0};

int main(){
	int start = 0;
	for(int i=0; i<3; ++i){
		for(int j=0; j<3; ++j){
			int temp;
			cin >> temp;
			if (temp == 0){
				temp = 9;
			}
			
			start = start*10 + temp;
		}
	}
	queue<int> q;
	map<int , int > dist;
	dist[start] = 0;
	q.push(start);
	
	while(!q.empty()){
		int now_num = q.front();
		string now = to_string(now_num);
		q.pop();
		
		int nn = now.find(9); 	// 9의 위치
		int x = nn/3;			// 9의 위치의 행값
		int y = nn%3;			// 9의 위치의 열값
		
		for(int k=0; k<4; ++k){
			int nx = x+dx[k];
			int ny = y+dy[k];
			
			if(nx >= 0 & nx < 3 && ny >= 0 && ny < 3){
				string next = now;
				swap(next[3*x+y] , next[3*nx + ny]);
				int num = stoi(next);
				if(dist.count(num) == 0){
					dist[num] = dist[now_num] + 1;
					q.push(num);
				}
			}
		}
	}
	
	if(dist.count(123456789) == 0){
		cout << -1 << endl;
	} else{
		cout << dist[123456789] << endl;
	}
	return 0;
}








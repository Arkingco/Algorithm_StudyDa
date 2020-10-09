
// 상태공간문제

#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<string>
using namespace std;
int dx[] = {0 , 0 , 1 , -1};
int dy[] = {1 , -1 , 0 , 0};
int play(){
	int puzzleList = 0;
	for(int i=0; i<3; ++i){
		for(int j=0; j<3; ++j){
			int value;
			cin >> value;
			if(value == 0){
				value = 9;
			}
			puzzleList = (puzzleList*10) + value;
		}
	}
	queue<int> q;
	map<int , int > dist;
	if(puzzleList==123456789) return 0;
	dist[puzzleList] = 0;
	q.push(puzzleList);
	// BFS시작
	while(!q.empty()){
		int hereNum = q.front();
		string hereNum_toString = to_string(hereNum);
		q.pop();
		int find9 = hereNum_toString.find('9');
		int x = find9/3;
		int y = find9%3;
		
		for(int i=0; i<4; ++i){
			int rx = dx[i]+ x;
			int ry = dy[i]+ y;
			if(rx >= 0 && rx < 3 && ry >= 0 && ry < 3 ){
				string next = hereNum_toString;
				swap(next[3*x + y] , next[3*rx + ry]);
				int num = stoi(next);
				if(dist.count(num) == 0){
					if(num == 123456789) return dist[hereNum] + 1;
					dist[num] = dist[hereNum] + 1;
					q.push(num);
				}
			}
		}
	}
	return -1;
}
int main(){
	cout << play() << endl;
}








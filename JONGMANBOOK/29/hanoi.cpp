#include<iostream>
using namespace std;

const int MAX_DISCS = 12;
int get(int state, int index){
	return (state >> (index * 2)) & 3
}
int set(int state, int index, int value){
	return (state & ~(3 << (index * 2))) | (value << (index * 2));
}
int c[1<<(MAAX_DISCS*2)];
// discs개의 원반이 있고, 각 원반읜 시작 위치와 목표 위치가
// begin,end에 주어질 때 최소 움직임의 수를 계산한다
int bfs(int discs, int begin, int end){
	
}
int main(){
	
}
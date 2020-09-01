#include<iostream>
#include<vector>
using namespace std;

const int MAX = 9;
int n,m;
int arr[MAX];
bool visited[MAX];

void backTracking(int count){
	int i;
	if(count == m){
		for(i=0; i< m -1; ++i) if(arr[i] > arr[i+1]) return;
		// 즉 배열의 끝 까지 다 도달했는지
		if(i == m-1) {
			for(int j=0; j<m; ++j){
				printf("%d ",arr[j]);
			}
			printf("\n");
		}
		
	}
	for(int i=1; i<=n; ++i){
		if(visited[i] == false){
			visited[i] = true;
			arr[count] = i;
			backTracking(count+1);
			visited[i] = false;
		}
	}
}
int main(){
	cin >> n  >> m;
	backTracking(0);
	
}
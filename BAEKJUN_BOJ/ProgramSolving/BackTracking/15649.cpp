#include<iostream>
#include<vector>
using namespace std;

const int MAX = 9;
int n,m;
int arr[MAX];
bool visited[MAX];

void backTracking(int count){
	if(count == m){
		for(int i=0; i<m; ++i){
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
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
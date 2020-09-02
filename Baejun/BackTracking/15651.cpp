#include<iostream>
using namespace std;

int n,m;
const int MAX = 9;
int arr[MAX];
bool visited[MAX];
void backTracking(int cnt){
	if(cnt == m){
		for(int i=0; i<m; ++i){
			printf("%d ",arr[i]);
		}
		cout << "\n";
		return;
	}
	for(int i=1; i<=n; ++i){
		visited[i] = true;
		arr[cnt] = i;
		backTracking(cnt + 1);
		visited[i] = false;
	}
}

int main(){
	cin >> n >> m;
	backTracking(0);
}
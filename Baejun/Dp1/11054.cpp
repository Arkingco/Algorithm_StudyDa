#include<iostream>
#include<vector>
using namespace std;

int binary_search(int Arrays[], int start, int end, int key) { // 탐색 범위는 [start,end) 이다. 
    if( start==end ) return start; // 탐색을 더 할 필요가 없는 경우 
     
    int middle = (start+end)/2;
    if( Arrays[middle] < key ) { // [middle+1,end) 구간으로 범위 축소
        return binary_search(Arrays,middle+1,end,key);
    }
    else if( Arrays[middle] > key ) { // [start,middle) 구간으로 범위 축소
         return binary_search(Arrays,start,middle,key);
    }
    else return middle;
}

int LIS[1001];
int length[1001];
int n;
int main(){

	cin >> n;
	for(int i=0; i<n; ++i){
		int value;
		cin >> value;
		length[i] = value;
	}
	
	LIS[0] = length[0];
	int lis_length = 0;
	for(int i=1; i<=n; ++i){
		if(length[i-1] < length[i]) {
			lis_length++;
			LIS[lis_length] = length[i];
		} else {
			int bino = binary_search(LIS, 0, i,length[i]);
			LIS[bino] = length[i];	
		}
		
	}
	for(int i=0; i<lis_length; ++i){
		cout << LIS[i] << " ";
	}
}
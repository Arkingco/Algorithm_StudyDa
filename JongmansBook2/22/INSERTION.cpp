#include<iostream>
#include<vector>
using namespace std;

// 유명한 정렬 알고리즘인 삽입 정렬은 정렬된 부분 배열을 유지하여 이 배열에 새 원소를 삽입해 나가는 방식으로 동작합니다.
// 주어진 정수 배열 A를 정렬하는 삽입 정렬의 구현은 다음과 같습니다.

void insertionSort(vector<int>& A) {
	for(int i=0; i<A.size(); ++i) {
		// A[0 .. i-1] 에 A[i]를 끼워 넣는다.
		int j=i;
		while(j > 0 && A[j-1] > A[j]) {
			swap(A[j-1], A[j]);
			j--;
		}
	}
}
int main() {
	
	int T;
	cin >> T;
	while(T--) {
		int n; 
		cin >> n;

		vector<int> sortingValue(n);
		vector<int> anser(n);
		
		for(int i=0; i<n; ++i) {
			sortingValue[i] = i+1;
		}
		for(int i=0; i<n; ++i) {
			int value;
			cin >> anser[i];
		}
		
		int Nvalue = n;
		while(Nvalue != 0) {
			
			int idx = Nvalue - anser[Nvalue-1]-1;
			for(int i=0; i<anser[Nvalue-1]; ++i) {
				swap(sortingValue[idx+i],sortingValue[idx+i+1]);
			}
			
			Nvalue--;
		}
		for(int i=0; i<n; ++i) {
		cout << sortingValue[i] << " ";
		}
		cout << endl;
		
	}
	
	
}
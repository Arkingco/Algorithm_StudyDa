#include<iostream>
#include<vector>
using namespace std;

struct RMQ {
	// 배열의 길이
	int n;
	// 각 구간의 최소치
	vector<int> rangeMin;
	RMQ(const vector<int>& array) {
		
		n = array.size(); 
		rangeMin.resize(n*4);
		init(array, 0, n-1, 1);
	}
	int init(const vector<int>& array, int left, int right, int node) {
		// 기저 사례
		if(right == left) return rangeMin[node] = array[left];
		int mid = (left + right) / 2;
		int leftMin = init(array, left, mid, node*2);
		int rightMin = init(array, mid+1, right, node*2 +1);
		return rangeMin[node] = min(leftMin, rightMin);
	}
};

int main() {
	int n;
	cin >> n;
	vector<int> list(n);
	for(int i=0; i<n; ++i ) {
		cin >> list[i];
	}
	
	RMQ* rmq = new RMQ(list);
	
	for(int i=0; i<rmq->rangeMin.size(); ++i) {
		cout << rmq->rangeMin[i] << " ";
	}
}
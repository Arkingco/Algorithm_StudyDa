#include<iostream>
#include<vector>
using namespace std;

const int INT_MAX = 987654321;
const int INT_MIN = -1;
struct RMQ {
	int n;
	vector<int> rangeMin;
	RMQ(const vector<int>& array) {
		n = array.size(); 
		rangeMin.resize(n*4);
		init(array, 0, n-1, 1);
	}
	int init(const vector<int>& array, int left, int right, int node) {
		if(right == left) return rangeMin[node] = array[left];
		int mid = (left + right) / 2;
		int leftMin = init(array, left, mid, node*2);
		int rightMin = init(array, mid+1, right, node*2 +1);
		return rangeMin[node] = min(leftMin, rightMin);
	}
	
	int query(int left, int right, int node, int nodeLeft, int nodeRight) {
		if(right < nodeLeft || nodeRight < left) return INT_MAX;
		if(left <= nodeLeft && nodeRight <= right) 
			return rangeMin[node];
		int mid = (nodeLeft + nodeRight) / 2;
		return min(query(left, right, node*2, nodeLeft, mid), query(left, right, node*2+1, mid+1, nodeRight));
	}
	
	int query(int left, int right) {
		return query(left, right, 1, 0, n-1);
	}
};

int main() {
	int C;
	cin >> C;
	
	while(C--) {
		int n, q;
		cin >> n >> q;
		
		vector<int> list(n);
		for(int i=0; i<n; ++i) {
			cin >> list[i];	
		}	
		RMQ* rmq = new RMQ(list);
		for(int i=0; i<n; ++i)
			list[i] = list[i]*-1;
		RMQ* rmqMax = new RMQ(list);
		while(q--) {
			int lowH, highH;
			cin >> lowH >> highH;
			
			int minResult = rmq -> query(lowH, highH);
			int maxResult = rmqMax -> query(lowH, highH);

			cout << (maxResult + minResult) * -1 << endl;
		}	
	}
}






#include<iostream>
#include<vector>
using namespace std;

struct FenwickTree {
	vector<int> tree;
	FenwickTree(int n) : tree(n + 1) {
	}
	// A[o...pos] 구간의 합을 구한다.
	int sum(int pos) {
		// 인덱스가 1부터 시작한다고 생각하자
		++pos;
		int ret = 0;
		while(pos > 0) {
			ret += tree[pos];
			// 다음 구간을 지우기 위해 최종 비트를 지운다.
			pos &= (pos - 1);
		}
		
		return ret;
	}
	//A[pos]에 val을 더한다.
	void add(int pos, int val) {
		++pos;
		while(pos < tree.size()) {
			tree[pos] += val;
			pos += (pos & -pos);
		}
	}
};

long long countMoves(const vector<int>& A) {
	FenwickTree tree(100000);
	long long result = 0;
	
	for(int i=0; i<A.size(); ++i) {
		result += tree.sum(99999) - tree.sum(A[i]);
		tree.add(A[i], 1);
		cout << tree.sum(99999) << " -  " << tree.sum(A[i]) << endl;
	}
	
	return result;
}

int main() {
	int T;
	cin >> T;
	
	while(T--) {
		int n;
		cin >> n;
		vector<int> treeList(n);
		
		for(int i=0; i<n; ++i) {
			cin >> treeList[i];
		}
		
		cout << countMoves(treeList) << endl;
	}
}
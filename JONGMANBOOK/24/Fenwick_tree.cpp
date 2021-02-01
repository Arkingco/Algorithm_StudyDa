#include<iostream>
#include<vector>
using namespace std;

struct FenwickTree {
	vector<int> tree;
	FenwickTree(vector<int>& treeList) : tree(treeList.size()+1, 0) {
		for(int i=0; i<treeList.size(); ++i) {
			add(i, treeList[i]);
		}
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
	int sum(int Left, int Right)
    {
        return sum(Right) - sum(Left - 1);
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

int main() {
	int n;
	cin >> n;
	vector<int> treeList(n);
	for(int i=0; i<n; ++i) {
		cin >> treeList[i];
	}
	
	FenwickTree* tree = new FenwickTree(treeList);
	
	for(int i=1; i<=n; ++i) {
		cout << tree->tree[i] << " ";
	} 
	cout << endl;
	cout << tree->sum(0,4)<< endl;
	int a=10;
	cout << (a += (10 & -10))  << endl;
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode {
	vector<TreeNode*> children;
};
int N,longest;
int heights(TreeNode* root) {
	
	vector<int> height;
	for(int i=0; i<root->children.size(); ++i ) {
		heights.push_back(height(root->children[i]));
	}
	if(height.size() == 0) return 0;
	
	sort(height.begin(), height.end());
	
	if(height.size() >= 2) {	
		longest = max(longest, 2 + height[height.size()-2] + height[height.size() - 1] );
	}
	
	return height.back() + 1;
}

int solve(TreeNode* root) {
	longest = 0;
	int h = height(root);
	return max(longest, h);
}

// root 성벽을 루트로 하는 트리를 생성한다.
TreeNode* getTree(int root) {
	TreeNode* ret = new TreeNode();
	for(int ch = 0; ch < n; ++ch) {
		// ch 성벽이 root 성벽에 직접적으로 포함되어 있다면
		// 트리를 만들고 자손 목록에 추가한다.
		if(isChild(root, ch)) {
			ret->children.push_back(getTree(ch));
		}
	}
	return ret;
}

// 입력 데이터
int n, y[100], x[100], radius[100];

// x^2를 반환한다.
int sqr(int x) {
	return x*x;
}
// 두 성벽 a,b의 중심점 간의 거리의 제곱을 반환한다
int sqrdist(int a, int b) {
	return sqr(y[a] - y[b]) + sqr(x[a] - x[b]));
}
// 성벽 a가 성벽 b를 포함하는지 확인한다.
bool encloses(int a, int b) {
	// 성벽 a의 반지름이 성벽 b의 반지름 보다 크고
	// 두 성벽 a,b의 중심점 거리가 (a의반지름 - b의반지름)
	return radius[a] > radius[b] && sqrdist(a, b) < sqr(radius[a] - radius[b]);
}

// '성벽' 트리에서 parent가 child의 부모인지 확인한다.
bool isChild(int parent, int child) {
	
	// parent는 child를 꼭 직접 포함해야 한다.
	if(!encloses(parent, child)) return false;
	
	for(int i=0; i<n; ++i) {
		if(i != parent && i != child && encloses(parent, i) && encloses(i, child)) {
			return false;
		}
	}
	return true;
}

int main() {
	int C;
	cin >> C;
	while(C--) {
		cin >> N;
		for(int i=0; i<N; ++i) {
			int x, y, r;
			cin >> x >> y >> r;
		}
	}
}
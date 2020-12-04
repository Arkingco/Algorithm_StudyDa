#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode {
	string label; // 저장할 자료(물론 꼭 문자열일 필요는 없다.)
	TreeNode* parent; // 부모노드를 가리키는 포인터
	vector<TreeNode*> children; // 자손노들을 가리키는 포인터 배열
};

TreeNode rootNode, node16, node54, node9, node12, node36, node72;

// 전위 순회
// 주어진 트리의 각 노드에 저장된 값을 모두 출력한다.
void preorder_printLables(TreeNode* root) {
	// 루트에 저장된 값을 출력한다.
	cout << root-> label << " ";
	// 각 자손들을 루트로 하는 서브트리에 포함된 값들을 재귀적으로 출력한다.
	for(int i=0; i<root->children.size(); ++i) {
		preorder_printLables(root->children[i]);
	}	
}


// 중위 순회
// 주어진 트리의 각 노드에 저장된 값을 모두 출력한다.
void inorder_printLables(TreeNode* root) {
	// 루트에 저장된 값을 출력한다.
	// 각 자손들을 루트로 하는 서브트리에 포함된 값들을 재귀적으로 출력한다.
	
	if(root->children.size() == 0) {
		cout << root-> label << " ";
		return;
	} else if(root->children.size() == 1) {
		inorder_printLables(root->children[0]);

		cout << root-> label << " ";
		
	} else if(root->children.size() == 2) {
		inorder_printLables(root->children[0]);

		cout << root-> label << " ";

		inorder_printLables(root->children[1]);
	}
}


// 후위 순회
// 주어진 트리의 각 노드에 저장된 값을 모두 출력한다.
void postorder_printLables(TreeNode* root) {
	// 각 자손들을 루트로 하는 서브트리에 포함된 값들을 재귀적으로 출력한다.
	for(int i=0; i<root->children.size(); ++i) {
		postorder_printLables(root->children[i]);
	}	
	// 루트에 저장된 값을 출력한다.
	cout << root-> label << " ";
}
void addNode(TreeNode* parentNode, TreeNode* nodeToAdd) {
	parentNode->children.push_back(nodeToAdd);
}

// 트리 순회 순서 변경 문제풀이
vector<int> slice(const vector<int>& v, int a, int b) {
	return vector<int>(v.begin() + a, v.begin() + b);
}

// 아름답구만...
// 트리의 전위탐색 결과와 중위탐색 결과가 주어질 때 후위탐색 결과를 출력한다.
void printPostOrder(const vector<int>& preorder, const vector<int>& inorder) {
	// 트리에 포함된 노드의 수
	const int N = preorder.size();
	// 기저 사례:텅 빈 트리면 곧장 종료
	if(preorder.empty()) return;
	// 이 트리의 루트는 전위 탐색 결과로부터 곧장 알 수 있다.
	const int root = preorder[0];
	// 이 트리의 왼쪽 서브 트리의 크기는 중위 탐색 결과에서 루트의 위치를 찾아서 알 수 있다.
	const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();
	const int T = N-1-L;
	// 왼쪽 서브트리 검색
	printPostOrder(slice(preorder, 1, L+1), slice(inorder, 0, L));
	printPostOrder(slice(preorder, L+1, N), slice(inorder, L+1, N));
	cout << root << " ";
}

int main() {
	
	int C, N;
	cin >> C >> N;
	while(C--) {
		vector<int> preorder, inorder;
		int value;
		for(int i=0; i<N; ++i) {
			cin >> value;
			preorder.push_back(value);
		}
		for(int i=0; i<N; ++i) {
			cin >> value;
			inorder.push_back(value);
		}
		
		printPostOrder(preorder, inorder);
		cout << "\n";
	}
	
	
	
}








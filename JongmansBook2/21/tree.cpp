// i'm back	2020.12.04
#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	string label; // 저장할 자료(물론 꼭 문자열일 필요는 없다.)
	TreeNode* parent; // 부모노드를 가리키는 포인터
	vector<TreeNode*> children; // 자손노들을 가리키는 포인터 배열
};

// 주어진 트리의 각 노드에 저장된 값을 모두 출력한다.
void printLables(TreeNode* root) {
	// 루트에 저장된 값을 출력한다.
	cout << root-> label << " ";
	// 각 자손들을 루트로 하는 서브트리에 포함된 값들을 재귀적으로 출력한다.
	for(int i=0; i<root->children.size(); ++i) {
		printLables(root->children[i]);
	}	
}

int main() {
	TreeNode root;
	root.label = "hi";
	
	TreeNode node1;
	node1.label = "my name";
	root.children.push_back(&node1);
	
	TreeNode node2;
	node2.label = "is";
	root.children.push_back(&node2);
	
	TreeNode node3;
	node3.label = "Arkingco";
	root.children.push_back(&node3);
	
	printLables(&root);
}








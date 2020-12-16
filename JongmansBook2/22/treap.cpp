#include<iostream>
using namespace std;

typedef int KeyType;
// 트립의 한 노드를 저장한다.

struct Node {
	// 노드에 저장된 원소
	KeyType key;
	// 이 노드의 우선순위(priority)
	// 이 노드를 루트로 하는 서브트리의 크기(size)
	int priority, size;
	// 두 자식 노드의 포인터
	Node *left, *right;
	// 생성자에서 난수 우선순위를 생성하고, size와 left/right를 초기화한다.
	Node(const KeyType& _key) : key(_key), priority(rand()), size(1) , left(NULL), right(NULL) {
		
	}
	void setLeft(Node* newLeft) {
		left = newLeft;
		calcSize();
	}
	void setRight(Node* newRight) {
		right = newRight;
		calcSize();
	}
	// size 멤버를 갱신한다.
	void calcSize() {
		size = 1;
		// left 자식 노드들의 사이즈 합을 부모노드에 더해준다.
		if(left) size += left->size;
		// right 자식 노드들의 사이즈 합을 부모노드에 더해준다.
		if(right) size += right->size;
	}
};

typedef pair<Node*, Node*> NodePair;
// root를 루트로 하는 트립을 key 미만의 값과 이상읠 값을 갖는
// 두 개의 트립으로 분리한다.
NodePair split(Node* root, KeyType key) {
	if(root == NULL) return NodePair(NULL, NULL);
	// 루트가 key 미만이라면 오른쪽 서브트리를 쪼갠다.
	if(root -> key < key ) {
		NodePair rs = split(root -> right, key);
		root->setRight(rs.first);
		return NodePair(root, rs.second);
		
	}
	// 루트가 key 이상이라면 왼쪽 서브트리를 쪼갠다.
	NodePair ls = split(root->left, key);
	root->setLeft(ls.second);
	return NodePair(ls.first, root);
}

// root를 루트로 하는 트립에 새 노드 node를 삽입한 뒤 결과 트립의 루트를 반환한다.
Node* insert(Node* root, Node* node ) {
	if(root == NULL) return node;
	// node가 루트를 대처해야 한다. 해당 서브트리를 반으로 잘라 각각 자손으로 한다.
	if(root->priority < node->priority) {
		NodePair splitted = split(root, node->key);
		node->setLeft(splitted.first);
		node->setRight(splitted.second);
		return node;
	}
	else if(node->key < root->key) {
		root->setLeft(insert(root->left, node));
	}
	else {
		root->setRight(insert(root->right, node));
	}
	return root;
}
int main() {
	
}
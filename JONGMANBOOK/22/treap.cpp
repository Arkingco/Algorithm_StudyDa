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
	// NodePair 은 리턴할 값
	if(root == NULL) return NodePair(NULL, NULL);
	// 분리할 것 root의 key 가 node의 키 key보다 작은경우
	if(root -> key < key) {
		// 결국 밖에선 노드와 루트에 붙일 애들을 찾는거임 rs.first 는 노드의 왼쪽 rs.second 는 노드의 오른쪽
		// 여기서 나온 rs.first값은 key보다 작은 값이고 그러면 root의 오른쪽에 대입한다.
		NodePair rs = split(root->right, key);
		root->setRight(rs.first);
		return NodePair(root, rs.second);
		
	}
	// 큰경우
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

Node* merge(Node* a, Node* b) {
	if(a == NULL) return b;
	if(b == NULL) return a;
	if(a->priority < b->priority) {
		b->setLeft(merge(a, b->right));
		return b;
	}
	a->setRight(merge(a->right, b));
	return a;
}

Node* erase(Node* root, KeyType key) {
	if(root == NULL) return root;
	// root를 지우고 양 서브트리를 합친 뒤 반환한다.
	if(root->key == key) {
		Node* ret = merge(root->left, root->right);
		delete root;
		return ret;
	}
	if(root->key > key) {
		root->setLeft(erase(root->left, key));
	}
	else {
		root->setRight(erase(root->right, key));
	}
	return root;
}

void inorder(Node* root)
{
        if(root!=NULL)
        {
                inorder(root->left);
                cout<<root->key<<' ';
                inorder(root->right);
        }
        return;
}
Node* kth(Node* root, int k) {
	// 왼쪽 서브트리의 크기를 우선 계산한다.
	int leftSize = 0;
	if(root->left != NULL) leftSize = root->left->size;
	if(k <= leftSize ) return kth(root->left, k);
	if(k == leftSize + 1 ) return root;
	return kth(root->right, k - leftSize - 1);
}
Node* findValue(Node* root, KeyType key) {
	if(root == NULL) return root;
	if(root->key == key) return root;
	if(root->key > key) findValue(root->left, key);
	else {
		findValue(root->right, key);
	}
	return root;
}
void CountLess(Node* root, KeyType key) {
	Node* findNode = findValue(root, key);
	cout << findNode->left->size << endl;
}
int main(void)
{
	//테스트 코드 시작

	Node* root=NULL; ///< 트립 선언
	//[0,9]의 숫자를 오름차순으로 삽입
	for(int i=0;i<10;i++)
	{
			root=insert(root,new Node(i));
	}
	//트립을 중위순회
	inorder(root);
	cout<<endl;
	//트립에서 1,6,5,8의 값을 삭제
	root=erase(root,1);
	root=erase(root,6);
	root=erase(root,5);
	root=erase(root,8);
	//트립을 중위순회
	inorder(root);
	cout<<endl;
	CountLess(root, 4);
	cout << endl;
	cout << kth(root, 2)->key << endl;
	//테스트 코드 끝
	return 0;
}
		
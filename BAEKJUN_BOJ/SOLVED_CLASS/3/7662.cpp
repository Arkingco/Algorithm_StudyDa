#include<algorithm>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<deque>
#include<map>
using namespace std;

struct Node {

	Node() {
		label = 0;
		left = NULL;
		right = NULL;
		parent_node = NULL;
	}

	int label;
	Node* left;
	Node* right;
	Node* parent_node;
};

struct duel_priority_queue {

	Node* root;
	int size;
	duel_priority_queue() {
		root = NULL;
		size = 0;
	}

	void insert(Node* thisNode,int value) {
		if (size == 0) {
			root = new Node();
			root->label = value;
			size++;

			return;
		}

		if (thisNode->label > value) {
			if (thisNode->left == NULL) {
				thisNode->left = new Node();
				thisNode->left->label = value;
				thisNode->left->parent_node = thisNode;
				size++;
			}
			else {
				insert(thisNode->left, value);
			}

		}
		else if (thisNode->label < value) {
			if (thisNode->right == NULL) {
				thisNode->right = new Node();
				thisNode->right->label = value;
				thisNode->right->parent_node = thisNode;
				size++;
			}
			else {
				insert(thisNode->right, value);
			}
		}
	}

	void print(Node* thisNode) {
		if (thisNode == NULL) return;
		if (thisNode->left != NULL) {
			print(thisNode->left);
		}

		cout << thisNode->label << endl;

		if (thisNode->right != NULL) {
			print(thisNode->right);
		}

	}

	void pop_back(Node* thisNode) {
		delete thisNode;
	}

};

int main() {

	duel_priority_queue* q = new duel_priority_queue();

	q->insert(q->root ,10);
	q->print(q->root);

	q->pop_back(q->root);

}
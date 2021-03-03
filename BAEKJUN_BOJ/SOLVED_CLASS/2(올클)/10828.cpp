#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

struct Node {
	int value;
	Node* next;

	Node(int inputValue) {
		value = inputValue;
		next = NULL;
	}
};

struct sstack {
	int size;
	Node* top;
	
	sstack() {
		size = 0;
		top = NULL;
	}

	void push(int value) {
		Node* newNode = new Node(value);

		if (top == NULL) {
			top = newNode;
		}
		else {
			newNode->next = top;
			top = newNode;
		}
		size = size + 1;
	}

	void pop() {
		if (size != 0) {
			Node* nextNode;

			cout << top->value << endl;
			if (top->next != NULL) {
				nextNode = top->next;
				delete top;
				top = nextNode;
			}
			else {
				delete top;
			}

			size = size - 1;
		}
		else {
			cout << -1 << endl;
			return;
		}
	}

	int get_size() {
		return size;
	}

	int empty() {
		if (size == 0)
			return 1;
		else
			return 0;
	}

	void print_top() {
		if (size == 0) {
			cout << "-1" << endl;
		} else {
			cout << top->value << endl;
		}
	}
};

int main()
{
	sstack st;

	int n;
	cin >> n;

	while(--n) {
		string input;
		cin >> input;

		if (input == "push") {
			int value;
			cin >> value;

			st.push(value);
		}
		if (input == "pop") {
			st.pop();
		}
		if (input == "size") {
			cout << st.get_size() << endl;
		}
		if (input == "empty") {
			cout << st.empty() << endl;
		}
		if (input == "top") {
			st.print_top();
		}
	
	}
	
}

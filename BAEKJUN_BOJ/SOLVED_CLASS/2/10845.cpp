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

struct qqueue {
	int size;
	Node* top;
	Node* bottom;

	qqueue() {
		size = 0;
		top = NULL;
	}

	void push(int value) {
		Node* newNode = new Node(value);

		if (top == NULL) {
			top = newNode;
			bottom = newNode;
		}
		else {
			bottom->next = newNode;
			bottom = newNode;
		}
		size = size + 1;
	}

	void pop() {
		if (size != 0) {
			Node* nextNode;

			cout << top->value << '\n';
			if (top->next != NULL) {
				nextNode = top->next;
				delete top;
				top = nextNode;
			}
			else {
				top = NULL;
				delete top;
			}

			size = size - 1;
		}
		else {
			cout << -1 << '\n';
			return;
		}
	}

	int get_size() {
		return size;	
	}

	int empty() {
		if (size == 0 && top == NULL)
			return 1;
		else
			return 0;
	}
	void print_front() {
		if (size == 0) {
			cout << "-1" << '\n';
		}
		else {
			cout << top->value << '\n';
		}
	}

	void print_back() {
		if (size == 0) {
			cout << "-1" << endl;
		} else {
			cout << bottom->value << '\n';
		}
	}
};

int main()
{
	qqueue st;

	int n;
	cin >> n;

	while(n--) {
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
			cout << st.get_size() << '\n';
		}
		if (input == "empty") {
			cout << st.empty() << '\n';
		}
		if (input == "front") {
			st.print_front();
		}
		if (input == "back") {
			st.print_back();
		}
	
	}
	
}

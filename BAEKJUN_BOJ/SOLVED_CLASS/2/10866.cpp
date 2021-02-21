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
	Node* front;
	Node(int inputValue) {
		value = inputValue;
		next = NULL;
		front = NULL;
	}
};

struct qqueue {
	int size;
	Node* top;
	Node* bottom;

	qqueue() {
		size = 0;
		top = NULL;
		bottom = NULL;
	}

	void push_front(int value) {
		Node* newNode = new Node(value);

		if (size == 0) {
			top = newNode;
			bottom = newNode;
		}
		else {
			newNode->next = top;
			top->front = newNode;
			top = newNode;
		}
		size = size + 1;
	}
	
	void push_back(int value) {
		Node* newNode = new Node(value);

		if (size == 0) {
			top = newNode;
			bottom = newNode;
		}
		else {
			newNode->front = bottom;
			bottom->next = newNode;
			bottom = newNode;
		}
		size = size + 1;
	}

	void pop_front() {
		
		if (size != 0) {
			Node* popNode = top;

			cout << popNode->value << endl;

			if (size == 1) {
				delete popNode;
			}
			else {
				top = top->next;
				top->front = NULL;
				delete popNode;
			}

			size = size - 1;
		}
		else {
			cout << "-1" << endl;
		}
		
	}

	void pop_back() {
		
		if (size != 0) {
			Node* popNode = bottom;

			cout << popNode->value << endl;
			if (size == 1) {
				delete popNode;
			}
			else {
				bottom = bottom->front;
				bottom->next = NULL;
				delete popNode;
			}

			size = size - 1;
		}
		else {
			cout << "-1" << endl;
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
	cin.tie(0);
	qqueue st;

	int n;
	cin >> n;

	while(n--) {
		string input;
		cin >> input;

		if (input == "push_front") {
			int value;
			cin >> value;

			st.push_front(value);
		}
		if (input == "push_back") {
			int value;
			cin >> value;

			st.push_back(value);
		}
		if (input == "pop_front") {
			st.pop_front();
		}
		if (input == "pop_back") {
			st.pop_back();
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

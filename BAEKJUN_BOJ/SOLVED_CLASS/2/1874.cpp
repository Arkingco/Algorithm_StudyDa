#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;

int main()
{
	vector<int> array(100001);
	queue<char> result;
	stack<int> A;
	stack<int> B;

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> array[i];
	}
	for (int i = n - 1; i >= 0; --i) {
		B.push(array[i]);
	}


	for (int i = 1; i <= n; ++i) {
		A.push(i);
		result.push('+');

		while ((!A.empty() && !B.empty()) && A.top() == B.top()) {
			A.pop();
			B.pop();
			result.push('-');
		}

	}

	if (A.size() != 0) {
		cout << "NO" << endl;
	}
	else {
		while (!result.empty()) {
			cout << result.front() << '\n';
			result.pop();
		}
	}

	
}

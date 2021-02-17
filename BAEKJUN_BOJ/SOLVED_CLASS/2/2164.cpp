#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;

int main() {

	int n;
	cin >> n;

	queue<int> array;

	for (int i = 1; i <= n; ++i) {
		array.push(i);
	}
	while (array.size() != 1) {
		array.pop();
		array.push(array.front());
		array.pop();
	}

	cout << array.front() << '\n';
}

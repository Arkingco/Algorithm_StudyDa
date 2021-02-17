#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;

// queue배열의 탑과 나머지를 비교해서 리턴해준다.
bool returnTop(queue<pair<int, int> > array) {
	int arrayTop = array.front().first;
	array.pop();

	while (!array.empty()) {
		if (array.front().first > arrayTop) {
			return false;
		}
		array.pop();
	}

	return true;
}
int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<int> result(n, 0);
		queue<pair<int, int> > array;
		for (int i = 0; i < n; ++i) {
			int value;
			cin >> value;
			array.push({ value, i });
		}

		while (!array.empty()) {
			if (returnTop(array)) {
				result[array.front().second] = n - array.size() + 1;
				array.pop();
			}
			else {
				array.push({ array.front().first, array.front().second });
				array.pop();
			}
		}

		cout << result[m] << '\n';
	}

}

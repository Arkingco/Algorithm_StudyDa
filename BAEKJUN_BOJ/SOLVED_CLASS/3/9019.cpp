#include<algorithm>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<deque>
#include<map>
#include<stack>
using namespace std;

bool visited[10001];
typedef pair<int, string> pis;

int a, b;

int getD(int value) {
	return (value * 2) % 10000;
}
int getS(int value) {
	return value == 0 ? 9999 : value - 1;
}
int getL(int value) {
	return ((value % 1000) * 10) + (value / 1000);
}
int getR(int value) {
	return (value / 10) + ((value % 10) * 1000);
}



string bfs() {
	
	queue<pis> q;
	string path;
	memset(visited, false, sizeof visited);
	q.push({ a, "" });

	visited[a] = true;
	while (!q.empty()) {
		pis here = q.front();
		q.pop();

		path = here.second;
		if (b == here.first) {
			return path;
		}

		int next = 0;
		next = getD(here.first);
		if (!visited[next]) {
			visited[next] = true;
			q.push({ next, path + "D" });
		}
		
		next = getS(here.first);
		if (!visited[next]) {
			visited[next] = true;
			q.push({ next, path + "S" });
		}

		next = getL(here.first);
		if (!visited[next]) {
			visited[next] = true;
			q.push({ next, path + "L" });
		}

		next = getR(here.first);
		if (!visited[next]) {
			visited[next] = true;
			q.push({ next, path + "R" });
		}
	}

}


int main() {
	int t;
	cin >> t;

	
	while (t--) {
		
		cin >> a >> b;

		string path = bfs();

		cout << path << '\n';
	}
}
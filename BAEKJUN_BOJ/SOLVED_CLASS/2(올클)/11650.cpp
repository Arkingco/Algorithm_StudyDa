#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
#include<math.h>
#include<cstdio>
using namespace std;

struct number {
	int x;
	int y;
};

bool compare(number a, number b) {
	// a가 b보다 적을때 오름차순 sort함수의 3번째 인자값인 함수는
	// 기본적으로 true를 반환하면 작동 하게 되어있다.
	// 즉 a < b 일 때 작동한다는 뜻은 내림차순으로 작동한다는 뜻이다. 

	return a.x == b.x ? a.y < b.y : a.x < b.x;
}

int main()
{
	cout.tie(0); cin.tie(0); ios::sync_with_stdio(0);

	int n;
	cin >> n;

	vector<number> anser;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		
		number num;
		num.x = x;
		num.y = y;
		anser.push_back(num);
	}

	sort(anser.begin(), anser.end(), compare);

	for (int i = 0; i < n; ++i) {
		cout << anser[i].x << " " << anser[i].y << '\n';
	}
}

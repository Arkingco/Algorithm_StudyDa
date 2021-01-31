//  2659번 : 십자 카드 문제 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX_CARD_SIZE = 4;
int timeCount(int value) {
	int temp = value;
	
	for(int i=0; i<MAX_CARD_SIZE; ++i) {
		value = (value % 1000 * 10) + value / 1000;
		if(temp > value) temp = value;
	}
	
	return temp;
}
int main() { 
	
	int a[MAX_CARD_SIZE];
	for(int i=0; i<MAX_CARD_SIZE; ++i) {
		cin >> a[i];
	}
	int result = timeCount(a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3] * 1);
		
	int ret = 0;

	// bi보다 다 작은 애들 이 범위
	for(int i=1111; i<=result; ++i) {
		
		// 만약 i와 timeCount(i) 가 다르다면 시계수가 아님
		if(timeCount(i) == i) ret++;
	}
	cout << ret << endl;
}
#include<iostream>
#include<cmath>s
using namespace std;

int findY;
int findX;
int funCount = 0;
bool alreadyFind = false;

void boardPlay(int y, int x, int size) {
	if (alreadyFind) {
		return;
	}

	// 정답보다 작은 값은 판별할 필요 없음
	if (y + size < findY || x + size < findX) {
		funCount = funCount + (size * size);
		return;
	}

	if (size == 1) {
		if (findY == y && findX == x) {
			alreadyFind = true;
			cout << funCount << endl;
		}
		funCount++;
	}
	else {
		size = size / 2;
		boardPlay(y, x, size);
		boardPlay(y + size, x, size);
		boardPlay(y, x + size, size);
		boardPlay(y + size, x + size, size);
	}
	
}


int main()
{
	int n;
	cin >> n >> findX >> findY;
	
	int size = pow(n, 2);
	boardPlay(0, 0, size);
	boardPlay(size, 0, size);
	boardPlay(0, size, size);
	boardPlay(size, size, size);
}

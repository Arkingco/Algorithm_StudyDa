#include<iostream>
using namespace std;
const int MAXN = 100;
const int INF = 987654321;
// n : 전공 과목의 수
// k : 들어야 할 과목의 수
// m : 학기의 수
// l : 한 학기에 최대로 들을 수 있는 과목의 수
int n, k, m , l;
// prerequsite[i] = i 번째 과목의 선수과목의 집합
int prerequsite[MAXN];
// classes[i] = i번째 학기에 개설되는 과목의 집합
int classes[MAXN];
int cache[MAXN][MAXN];
// n의 이진수 표현에서 켜진 비트의 수를 반환한다.
int bitCount(int bit){
	int ret = 0;
	
	for(int i=0; i<m; ++i){
		if( bit &=  (1 << i)) ret++;
	}
	
	return ret;
}
// 이번 학기가 semester이고, 지금까지 들은 과목의 집합이 taken 일 떄
// k개 이상의 과목을 모두 들으려면 몇 학기나 더 있어야 하는가?
// 불가능한 경우 INF를 반환한다.
int graduate(int semester , int taken){
	
	// 기저 사례 : k개 이상의 과목을 이미 들은경우
	if(bitCount(taken) >= k) return 0;
	// 기저 사례 : m학기가 전부 지난 경우
	if(semester >= m) return INF;
	// 메모이제이션
	int ret = cache[semester][taken];
	if(ret != -1 ) return ret;
	ret = INF;
	// 이번 학기에 들을 수 있는 과목 중 아직 듣지 않은 과목들을 찾는다.
	int canTake = (classes[semester] & (~taken));
	// 선수 과목을 다 듣지 않은 과목들을 걸러낸다.
	for(int i=0; i<n; ++i)
		if((canTake & ( 1 << i)) & ((taken & prerequsite[i]) != prerequsite[i]))
			canTake &= ~(1 << i);
	// 이 집합의 모든 부분을 순회한다.
	for(int take = canTake; take > 0; take = ((take - 1) & take)){
		// 한 학기에 l과목 까지만 들을 수 있다.
		if(bitCount(take) > l) continue;
		ret = min(ret , graduate(semester + 1 , taken | take) + 1) ;
	}	 
	// 이번 학기에 아무 것도 듣지 않을 경우
	ret = min(ret , graduate(semester+1 , taken));
	
	return ret;
}


int main(){
	
}
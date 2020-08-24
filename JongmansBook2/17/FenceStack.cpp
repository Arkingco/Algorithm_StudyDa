#include<iostream>
#include<vector>
#include<stack>

using namespace std;


vector<int> h;
int n;

int stackFence(){
	
	// 남아 있는 판자들의 위치
	stack<int> remaining;
	// 제일 끝 울타리 높이가 i번째 울타리 높이보다 작아야 범위가 설정 되므로
	h.push_back(0);
	
	// 정답 저장 
	int result = 0;
	for(int i=0; i<h.size(); ++i){
		// 스택 안에 아무것도 없지 않고 , 스택에서 가장 위에 있는 판이 
		while( !remaining.empty() && h[remaining.top()] >= h[i] ){
			int j = remaining.top();
			remaining.pop();
			int width = 0;
			// j번째 판자 왼쪽에 판자가 하나도 안 남아있는 경우 left[j] = -1,
			// 아닌 경우 left[j] = 남아 있는 판자 중 가장 오른쪽에 있는 판자 번호
			if(remaining.empty())
				width = i;
			else 
				width = (i - remaining.top() - 1);
			
			result = max(result , h[j] * width);
			
			cout << result << "  "  << h[j] <<  "  " << width  <<  "  " << j << endl;
		}
		remaining.push(i);
		cout << i << endl;
	}
	
	return result;
}





int Fence(){
	// 마지막 값을 0을 추가해서 범위를 지정한다.
	h.push_back(0);
	stack<int> remain;
	
	int result = 0;
	for(int i=0; i<h.size(); ++i){
		while(!remain.empty() && h[remain.top()] >= h[i]){
			int j = remain.top();
			remain.pop();
			int width = 0;
			if(!remain.empty())
				width = (i - remain.top() - 1);
			else 
				width = i;
			
			result = max(result , h[j] * width);
		}
		remain.push(i);
	}
	return result;
}







int main(){
	cin >> n;

	for(int i=0; i<n; ++i){
		int value;
		cin >> value;
		h.push_back(value);
	}
	
	cout << Fence() << endl;
}
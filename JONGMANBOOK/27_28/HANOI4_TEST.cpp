#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

int C , n;
vector<stack<int> > towers;
vector<stack<int> > anser_towers;
int hanoi4(vector<stack<int> > towers ){
	if(towers[4] == anser_towers[4]) return 1; 
	int ret = 0;
		for(int i=1; i<=4; ++i){
			for(int j=1; j<=4;++j){
				if(i!= j && (!towers[i].empty() && (towers[j].empty() ||towers[i].top() < towers[j].top()) ) ){
					towers[j].push(towers[i].top());
					towers[i].pop();
					ret = min(ret , hanoi4(towers)+1);
				}
			}
		}
	return ret;
}
int main(){
	cin >> C;

	while(C--){
		cin >> n;
		towers = vector<stack<int> > (5);
		anser_towers = vector<stack<int> > (5);
		for(int i=1;i<=4; ++i){
			int a;
			cin >> a;
			for(int j=0; j<a; ++j){
				int b;
				cin >> b;
				towers[i].push(b);
			}
		}
		for(int i=1;i<=4; ++i){
			int a;
			cin >> a;
			for(int j=0; j<a; ++j){
				int b;
				cin >> b;
				anser_towers[i].push(b);
			}
		}
		cout << hanoi4(towers) << endl;
	}
}
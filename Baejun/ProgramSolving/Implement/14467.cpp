#include<iostream>
#include<vector>
using namespace std;

const int MAX_COW_SIZE = 10;

int main() {
	int n;
	cin >> n;
	
	vector<int> cowlist[MAX_COW_SIZE+1];
	for(int i=0; i<n; ++i) {
		int a, b;
		cin >> a >> b;
		
		cowlist[a].push_back(b);
	}
	
	int retCount = 0;
	for(int i=1; i<=MAX_COW_SIZE; ++i) {
		if(cowlist[i].size() != 0) {
			int here = cowlist[i][0];
			
			for(int j=0; j<cowlist[i].size(); ++j) {
				if(here != cowlist[i][j]) {
					retCount++;
					here = cowlist[i][j];
				} else {
					
				}
			}
		}
	}
	
	cout << retCount << endl;
}
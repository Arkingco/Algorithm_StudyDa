#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

const int SQURD_MAP_MAX_SIZE = 4;
int squrd_map[4] = {1, 3, 2, 4};

int main() {
	vector<vector<int > > map = vector<vector<int > > (SQURD_MAP_MAX_SIZE + 1 , vector<int>(0,0));
	
	int n;
	cin >> n;
	
	for(int i=0; i<n; ++i) {
		int a, b;
		cin >> a >> b;
		
		map[a].push_back(b);
	}
	
	for(int i=1; i<=4; ++i) {
		sort(map[i].begin(), map[i].end());
		for(int j=0; j<map[i].size(); ++j) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	
	
}
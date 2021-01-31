#include<iostream>
#include<vector>
using namespace std;

typedef pair<int, int> ii;

int main() {
	
	int t;
	cin >> t;
	
	while(t--) {
		int a, b, k;
		cin >> a >> b >> k;
		
		vector<long long> A(a, 0);
		vector<long long> B(b, 0);
		
		long long ans = k*(k-1)/2;
		
		vector<int> A_input(k);
		vector<int> B_input(k);
		for(int i=0; i<k; ++i) {
			cin >> A[i];
		}
		
		for(int i=0; i<k; ++i) {
			cin >> B[i];
		}
		
		for(int i=0; i<k; ++i) {
			int ai, bi;
			ai = A_input[i];
			bi = B_input[i];
			
			ans -= A[ai] + B[bi];
			A[ai] += 1;
			B[bi] += 1;
		}
		
		printf("%lld\n", ans);
	}
}
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;



int main()
{
	int n, n2;
	cin >> n;

	vector<int> array(n);
	for (int i = 0; i < n; ++i) {
		cin >> array[i];
	}
	
	sort(array.begin(), array.end());

	cin >> n2;
	vector<char> result;
	for (int i = 0; i < n2; ++i) {
		
		int value;
		cin >> value;

		int start = 0;
		int end = n-1;
		bool isRight = false;
		while (start <= end) {

			int mid = (start + end) / 2;
			if (array[mid] > value) {
				end = mid - 1;
			}
			else if (array[mid] < value) {
				start = mid + 1;
			}
			else if(array[mid] == value){
				isRight = true;
				break;
			} 
		}

		if (isRight == true) {
			result.push_back('1');
		}
		else {
			result.push_back('0');
		}
	}
	
	for (int i = 0; i < result.size(); ++i) {
		cout << result[i] << '\n';
	}
}

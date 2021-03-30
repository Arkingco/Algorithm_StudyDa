#include<iostream>
using namespace std;

int S;

int main() { 

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	string selects[6] = { "add", "remove", "check", "toggle", "all", "empty" };
	
	S = 0;
	for (int i = 0; i < n; ++i) {
		string select;
		cin >> select;


		// add
		if (select == selects[0]) {
			int value;
			cin >> value; 

			S |= (1 << value);
		}

		// remove
		if (select == selects[1]) {
			int value;
			cin >> value;

			S &= ~(1 << value);
		}
		
		// check
		if (select == selects[2]) {
			int value;
			cin >> value;

			if (S & (1 << value)) {
				cout << "1" << '\n';
			}
			else {
				cout << "0" << '\n';
			}
		}

		// toggle
		if (select == selects[3]) {
			int value;
			cin >> value;

			if (S & (1 << value)) {
				S &= ~(1 << value);
			}
			else {
				S |= (1 << value);
			}
		}

		// all
		if (select == selects[4]) {
			S = (1 << 21) - 1;
		}

		// empty
		if (select == selects[5]) {
			S = 0;
		}

	}

}

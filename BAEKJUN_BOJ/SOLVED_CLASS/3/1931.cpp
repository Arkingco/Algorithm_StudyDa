#include<algorithm>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
using namespace std;

typedef pair<int, int> pii;

bool compare(pii a, pii b) {
	if (a.second < b.second) {
		return true;
	}
	else if (a.second == b.second) {
		return a.first < b.first ? true : false;
	}
	else {
		return false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<pii> meeting(n);

	for (int i = 0; i < n; ++i) {
		int start, end;
		cin >> start >> end;

		meeting[i] = { start, end };
	}

	// meeting.first = 미팅 시작 시간.
	// meeting.second = 미팅 종료 시간.

	sort(meeting.begin(), meeting.end(), compare);

	int lastMeetingTime = meeting[0].second;
	int countMeeting = 1;

	for (int i = 1; i < meeting.size(); ++i) {

		// meeting[i]의 시작 시간이 마지막 미팅 시간보다 빠르거나 같으면 카운트
		if (meeting[i].first >= lastMeetingTime) {
			countMeeting++;
			lastMeetingTime = meeting[i].second;
		}
	}

	cout << countMeeting << endl;
}

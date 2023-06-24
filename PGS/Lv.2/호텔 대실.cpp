#include <bits/stdc++.h>
using namespace std;

vector<int> end_time;

int transTime(string s) {
	int hour = stoi(s.substr(0, 2));
	int min = stoi(s.substr(3, 2));
	return hour * 60 + min;
}

int solution(vector<vector<string>> book_time) {
	int answer = 0;

	sort(book_time.begin(), book_time.end());

	for (int i = 0; i < book_time.size(); i++) {
		int sTime = transTime(book_time[i][0]);
		int eTime = transTime(book_time[i][1]) + 10;
		bool addRoom = true;

		for (int j = 0; j < end_time.size(); j++) {
			if (sTime >= end_time[j]) {
				end_time[j] = eTime;
				addRoom = false;
				break;
			}
		}

		if (addRoom) {
			end_time.push_back(eTime);
			answer++;
		}
	}

	return answer;
}
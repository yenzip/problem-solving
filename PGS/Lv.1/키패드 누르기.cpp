#include <bits/stdc++.h>
using namespace std;

map<int, pair<int, int>> keypad = {
	{1, {0, 0}}, {2, {0, 1}}, {3, {0, 2}},
	{4, {1, 0}}, {5, {1, 1}}, {6, {1, 2}},
	{7, {2, 0}}, {8, {2, 1}}, {9, {2, 2}},
	{'*', {3, 0}}, {0, {3, 1}}, {'#', {3, 2}}
};
int left_hand = '*', right_hand = '#';

int dist(int now, int target) {
	int nx = keypad[now].first;
	int ny = keypad[now].second;

	int tx = keypad[target].first;
	int ty = keypad[target].second;

	return (abs(tx - nx) + abs(ty - ny));
}

string solution(vector<int> numbers, string hand) {
	string answer = "";

	for (auto num : numbers) {
		if (num == 1 || num == 4 || num == 7) {
			answer += 'L';
			left_hand = num;
		}
		else if (num == 3 || num == 6 || num == 9) {
			answer += 'R';
			right_hand = num;
		}
		else {  // 2, 5, 8, 0
			int distL = dist(left_hand, num);
			int distR = dist(right_hand, num);

			if (distL == distR) {
				if (hand == "left") {
					left_hand = num;
					answer += 'L';
				}
				else {
					right_hand = num;
					answer += 'R';
				}
			}
			else if (distL < distR) {
				left_hand = num;
				answer += 'L';
			}
			else {
				right_hand = num;
				answer += 'R';
			}
		}
	}

	return answer;
}
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

map<int, pair<int, int>> keypad = { {1, {0, 0}}, {2, {0, 1}}, {3, {0, 2}},
									{4, {1, 0}}, {5, {1, 1}}, {6, {1, 2}},
									{7, {2, 0}}, {8, {2, 1}}, {9, {2, 2}},
									{'*', {3, 0}}, {0, {3, 1}}, {'#', {3, 2}} };

string solution(vector<int> numbers, string hand) {
	string answer = "";

	vector<int> left = { 1, 4, 7 };
	vector<int> right = { 3, 6, 9 };

	int pos_L = '*';
	int pos_R = '#';

	for (auto i : numbers) {
		if (find(left.begin(), left.end(), i) != left.end()) {	// 1, 4, 7
			answer += 'L';
			pos_L = i;
		}
		else if (find(right.begin(), right.end(), i) != right.end()) {	// 3, 6, 9
			answer += 'R';
			pos_R = i;
		}
		else {	// 2, 5, 8 -> 두 점 사이의 거리
			int x = keypad[i].first;
			int y = keypad[i].second;

			// 왼쪽 위치와 두 점 사이의 거리
			int x1 = keypad[pos_L].first;
			int y1 = keypad[pos_L].second;

			int dist_L = abs(x - x1) + abs(y - y1);


			// 오른쪽 위치와 두 점 사이의 거리
			int x2 = keypad[pos_R].first;
			int y2 = keypad[pos_R].second;

			int dist_R = abs(x - x2) + abs(y - y2);

			if (dist_L < dist_R) {
				answer += 'L';
				pos_L = i;
			}
			else if (dist_L > dist_R) {
				answer += 'R';
				pos_R = i;
			}
			else {
				if (hand == "left") {
					answer += 'L';
					pos_L = i;
				}
				else {
					answer += 'R';
					pos_R = i;
				}
			}
		}
	}
	
	return answer;
}
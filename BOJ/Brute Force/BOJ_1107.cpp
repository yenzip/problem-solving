#include <bits/stdc++.h>
using namespace std;

int N, M;
bool buttons[10];

int check(string s) {
	int count = 0;
	for (auto c : s) {
		if (!buttons[c - '0']) {
			return -1;
		}
		else {
			count++;
		}
	}
	return count;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	memset(buttons, true, sizeof(buttons));
	for (int i = 0; i < M; i++) {
		int block;
		cin >> block;
		buttons[block] = false;
	}

	int answer = abs(N - 100);	// 초기값 : 100에서 N으로 [+/-] 이용해 이동하는 횟수

	for (int channel = 0; channel <= 1000000; channel++) {
		int count = check(to_string(channel));	// channel이 고장난 버튼을 포함하는지 검사
		if (count != -1) {	// 해당 channel 이용 가능
			int move_one = abs(N - channel);	// channel에서 N으로 [+/-] 이용해 이동하는 횟수
			answer = min(answer, count + move_one);	// 최소 이동 횟수 갱신
		}
	}

	cout << answer << '\n';

	return 0;
}
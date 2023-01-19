#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	stack<char> left, right;	// left, right : 커서 왼/오른쪽
	int M;

	cin >> str >> M;
	
	for (char c : str) {
		left.push(c);
	}

	for (int i = 0; i < M; i++) {
		char cmd;

		cin >> cmd;

		if (cmd == 'L') {	// 커서 왼쪽 이동
			if (left.empty()) {
				continue;
			}
			right.push(left.top());
			left.pop();
		}
		else if (cmd == 'D') {	// 커서 오른쪽 이동
			if (right.empty()) {
				continue;
			}
			left.push(right.top());
			right.pop();
		}
		else if (cmd == 'B') {	// 커서 왼쪽 문자 삭제
			if (left.empty()) {
				continue;
			}
			left.pop();
		}
		else if (cmd == 'P') {	// 커서 왼쪽 문자 추가
			char c;
			cin >> c;
			left.push(c);
		}
	}

	while (!left.empty()) {	// 커서 왼쪽 스택 -> 오른쪽 스택으로 옮기기
		right.push(left.top());
		left.pop();
	}

	while (!right.empty()) {
		cout << right.top();
		right.pop();
	}

	return 0;
}
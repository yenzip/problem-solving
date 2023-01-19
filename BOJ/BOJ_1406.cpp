#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	stack<char> left, right;	// left, right : Ŀ�� ��/������
	int M;

	cin >> str >> M;
	
	for (char c : str) {
		left.push(c);
	}

	for (int i = 0; i < M; i++) {
		char cmd;

		cin >> cmd;

		if (cmd == 'L') {	// Ŀ�� ���� �̵�
			if (left.empty()) {
				continue;
			}
			right.push(left.top());
			left.pop();
		}
		else if (cmd == 'D') {	// Ŀ�� ������ �̵�
			if (right.empty()) {
				continue;
			}
			left.push(right.top());
			right.pop();
		}
		else if (cmd == 'B') {	// Ŀ�� ���� ���� ����
			if (left.empty()) {
				continue;
			}
			left.pop();
		}
		else if (cmd == 'P') {	// Ŀ�� ���� ���� �߰�
			char c;
			cin >> c;
			left.push(c);
		}
	}

	while (!left.empty()) {	// Ŀ�� ���� ���� -> ������ �������� �ű��
		right.push(left.top());
		left.pop();
	}

	while (!right.empty()) {
		cout << right.top();
		right.pop();
	}

	return 0;
}
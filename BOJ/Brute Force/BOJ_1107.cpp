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

	int answer = abs(N - 100);	// �ʱⰪ : 100���� N���� [+/-] �̿��� �̵��ϴ� Ƚ��

	for (int channel = 0; channel <= 1000000; channel++) {
		int count = check(to_string(channel));	// channel�� ���峭 ��ư�� �����ϴ��� �˻�
		if (count != -1) {	// �ش� channel �̿� ����
			int move_one = abs(N - channel);	// channel���� N���� [+/-] �̿��� �̵��ϴ� Ƚ��
			answer = min(answer, count + move_one);	// �ּ� �̵� Ƚ�� ����
		}
	}

	cout << answer << '\n';

	return 0;
}
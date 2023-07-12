#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[50];
deque<int> dq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> A[i];
	}

	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}

	int answer = 0;

	for (int i = 0; i < M; i++) {
		int beginDist = find(dq.begin(), dq.end(), A[i]) - dq.begin();	// �տ������� A[i]���� �Ÿ�
		int endDist = dq.end() - find(dq.begin(), dq.end(), A[i]);	// �ڿ������� A[i]���� �Ÿ�
		
		if (beginDist < endDist) {	// 2�� ����
			while (dq.front() != A[i]) {
				dq.push_back(dq.front());
				dq.pop_front();
				answer++;
			}
		}
		else {	// 3�� ����
			while (dq.back() != A[i]) {
				dq.push_front(dq.back());
				dq.pop_back();
				answer++;
			}
			dq.push_front(dq.back());	// A[i] ������ ������
			dq.pop_back();
			answer++;
		}

		dq.pop_front();	// 1�� ����
	}

	cout << answer;

	return 0;
}
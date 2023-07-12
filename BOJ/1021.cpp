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
		int beginDist = find(dq.begin(), dq.end(), A[i]) - dq.begin();	// 앞에서부터 A[i]까지 거리
		int endDist = dq.end() - find(dq.begin(), dq.end(), A[i]);	// 뒤에서부터 A[i]까지 거리
		
		if (beginDist < endDist) {	// 2번 연산
			while (dq.front() != A[i]) {
				dq.push_back(dq.front());
				dq.pop_front();
				answer++;
			}
		}
		else {	// 3번 연산
			while (dq.back() != A[i]) {
				dq.push_front(dq.back());
				dq.pop_back();
				answer++;
			}
			dq.push_front(dq.back());	// A[i] 앞으로 보내기
			dq.pop_back();
			answer++;
		}

		dq.pop_front();	// 1번 연산
	}

	cout << answer;

	return 0;
}
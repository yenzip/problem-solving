#include <bits/stdc++.h>
using namespace std;

int A, B, N;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> A >> B >> N;

	// ��� 1.) �켱���� ť �̿�
	priority_queue<int> pq;
	pq.push(-abs(B - A));	// [+/-]�θ� �̵�
	while (N--) {
		int bookmark;
		cin >> bookmark;
		pq.push(-(abs(B - bookmark) + 1));	// ���ã�⸦ ����� �̵�
	}
	cout << -pq.top() << '\n';

	// ��� 2.) �ݺ��� �̿�
	int answer = abs(B - A);	// [+/-]�θ� �̵�
	while (N--) {
		int bookmark;
		cin >> bookmark;
		answer = min(answer, abs(B - bookmark) + 1);	// ���ã�⸦ ����� �̵�
	}
	cout << answer << '\n';

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int A, B, N;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> A >> B >> N;

	// 방법 1.) 우선순위 큐 이용
	priority_queue<int> pq;
	pq.push(-abs(B - A));	// [+/-]로만 이동
	while (N--) {
		int bookmark;
		cin >> bookmark;
		pq.push(-(abs(B - bookmark) + 1));	// 즐겨찾기를 사용해 이동
	}
	cout << -pq.top() << '\n';

	// 방법 2.) 반복문 이용
	int answer = abs(B - A);	// [+/-]로만 이동
	while (N--) {
		int bookmark;
		cin >> bookmark;
		answer = min(answer, abs(B - bookmark) + 1);	// 즐겨찾기를 사용해 이동
	}
	cout << answer << '\n';

	return 0;
}
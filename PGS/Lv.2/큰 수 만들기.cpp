#include <bits/stdc++.h>
using namespace std;

string solution(string number, int k) {

	deque<char> dq;

	for (auto n : number) {
		while (!dq.empty() && k > 0 && dq.back() < n) {
			dq.pop_back();
			k--;
		}
		dq.push_back(n);
	}

	for (int i = 0; i < k; i++) {    // ����) ������ ���� ����(k)�� �����ִ� ���
		dq.pop_back();
	}

	return string(dq.begin(), dq.end());
}
#include <bits/stdc++.h>
using namespace std;

priority_queue<int> pq1;    // √÷¥Î»¸
priority_queue<int, vector<int>, greater<int>> pq2; // √÷º“»¸

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	int size = 0;

	for (auto op : operations) {
		char cmd = op[0];
		int val = stoi(op.substr(2));

		if (cmd == 'I') {
			pq1.push(val);
			pq2.push(val);
			size++;
		}
		else if (cmd == 'D') {
			if (size) {
				if (val == 1) {
					pq1.pop();
				}
				else if (val == -1) {
					pq2.pop();
				}
				size--;
			}
		}
		if (size == 0) {
			pq1 = priority_queue<int>();
			pq2 = priority_queue<int, vector<int>, greater<int>>();
		}
	}

	return size == 0 ? vector<int>{0, 0} : vector<int>{ pq1.top(), pq2.top() };
}
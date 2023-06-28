#include <bits/stdc++.h>
using namespace std;

int c;

bool comp(vector<int> &a, vector<int> &b) {
	if (a[c] == b[c]) {
		return a[0] > b[0];
	}
	return a[c] < b[c];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {

	c = col - 1;

	sort(data.begin(), data.end(), comp);   // 2.

	int answer = 0;

	for (int i = row_begin - 1; i < row_end; i++) {  // 3. & 4.
		int S = 0;
		for (int j = 0; j < data[i].size(); j++) {
			S += data[i][j] % (i + 1);
		}
		answer = answer ^ S;
	}

	return answer;
}
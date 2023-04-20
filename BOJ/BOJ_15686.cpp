#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[50][50];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

int check(string s) {
	int dist = 0;
	for (auto h : house) {
		int minVal = 1e9;
		for (auto c : s) {
			int n = c - '0';
			minVal = min(minVal, abs(chicken[n].first - h.first) + abs(chicken[n].second - h.second));
		}
		dist += minVal;
	}
	return dist;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				house.push_back({ i, j });
			}
			if (board[i][j] == 2) {
				chicken.push_back({ i, j });
			}
		}
	}

	int answer = 1e9;
	vector<int> idx(chicken.size(), 0);	// 조합 : 치킨집 중 M개 선택
	for (int i = 0; i < M; i++) {
		idx[i] = 1;
	}
	sort(idx.begin(), idx.end());
	do {
		string selection;
		for (int i = 0; i < chicken.size(); i++) {
			if (idx[i]) {
				selection += i + '0';
			}
		}
		answer = min(answer, check(selection));
	} while (next_permutation(idx.begin(), idx.end()));

	cout << answer;

	return 0;
}
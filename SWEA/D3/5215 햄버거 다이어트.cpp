#include <bits/stdc++.h>
using namespace std;

int N, L;
vector<pair<int, int>> v;
int answer;

void dfs(int idx, int curScore, int curCal) {
	if (curCal > L) {
		return;
	}

	if (idx == N) {
		answer = max(answer, curScore);
		return;
	}

	dfs(idx + 1, curScore + v[idx].first, curCal + v[idx].second);
	dfs(idx + 1, curScore, curCal);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> L;

		for (int i = 0; i < N; i++) {
			int score, cal;
			cin >> score >> cal;
			v.push_back({ score, cal });
		}

		answer = 0;
		dfs(0, 0, 0);

		cout << "#" << tc << " " << answer << "\n";

		v.clear();
	}

	return 0;
}
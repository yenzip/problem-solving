#include <bits/stdc++.h>
using namespace std;

int T, N, K;
vector<string> grade = { "A+","A0","A-","B+", "B0", "B-", "C+", "C0", "C-","D0" };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> K;
		vector<pair<double, int>> v;
		for (int i = 1; i <= N; i++) {
			int mid, fin, task;
			double total;
			cin >> mid >> fin >> task;
			total = mid * 0.35 + fin * 0.45 + task * 0.2;
			v.push_back({ total, i });
		}
		sort(v.rbegin(), v.rend());
		auto rank = distance(v.begin(), find_if(v.begin(), v.end(), [&](const auto& pair) { return pair.second == K; }));
		cout << '#' << t << ' ' << grade[rank / (N / 10)] << '\n';
	}

	return 0;
}
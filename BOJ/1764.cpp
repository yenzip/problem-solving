#include <bits/stdc++.h>
using namespace std;

int N, M;
string name;
vector<string> v;
vector<string> answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> name;
		v.push_back(name);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < M; i++) {
		cin >> name;
		if (binary_search(v.begin(), v.end(), name)) {
			answer.push_back(name);
		}
	}

	sort(answer.begin(), answer.end());
	cout << answer.size() << "\n";
	for (auto ans : answer) {
		cout << ans <<"\n";
	}

	return 0;
}
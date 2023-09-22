#include <bits/stdc++.h>
using namespace std;

int N, M;
string s;

struct Word {
	string word;
	int cnt;
};

struct comp {
	bool operator()(Word a, Word b) {
		if (a.cnt == b.cnt) {
			if (a.word.size() == b.word.size()) {
				return a.word > b.word;
			}
			return a.word.size() < b.word.size();
		}
		return a.cnt < b.cnt;

	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	map<string, int> m;

	for (int i = 0; i < N; i++) {
		cin >> s;

		if (s.size() >= M) {
			m[s]++;
		}
	}

	priority_queue<Word, vector<Word>, comp> pq;

	for (auto &entry : m) {
		pq.push({ entry.first, entry.second });
	}

	while (!pq.empty()) {
		cout << pq.top().word << "\n";
		pq.pop();
	}

	return 0;
}
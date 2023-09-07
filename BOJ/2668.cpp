#include <bits/stdc++.h>
using namespace std;

int N;
int A[101];
bool visited[101];
bool selected;

void dfs(int start, int now) {
	if (visited[now]) {
		if (start == now) {
			selected = true;
		}
		return;
	}

	visited[now] = true;
	dfs(start, A[now]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		A[i] = num;
	}

	int answer = 0;
	vector<int> number;

	for (int i = 1; i <= N; i++) {
		selected = false;
		memset(visited, false, sizeof(visited));
		dfs(i, i);
		if (selected) {
			answer++;
			number.push_back(i);
		}
	}

	cout << answer << "\n";

	for (int i = 0; i < number.size(); i++) {
		cout << number[i] << "\n";
	}

	return 0;
}
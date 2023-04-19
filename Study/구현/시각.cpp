#include <bits/stdc++.h>
using namespace std;

int N;
int answer = 0;

bool check(int i, int j, int k) {
	string s = to_string(i) + to_string(j) + to_string(k);
	return s.find('3') != string::npos;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < 60; j++) {
			for (int k = 0; k < 60; k++) {
				if (check(i, j, k)) {
					answer++;
				}
			}
		}
	}
	cout << answer;

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int N;
long long M;
long long S[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		S[i] = S[i - 1] + num;
	}
	
	int answer = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			if (S[i] - S[j - 1] == M) {
				answer++;
			}
		}
	}

	cout << answer;

	return 0;
}
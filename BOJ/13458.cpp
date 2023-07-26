#include <bits/stdc++.h>
using namespace std;

int N, B, C;
vector<int> A;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	A.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	cin >> B >> C;

	long long answer = N;

	for (int i = 0; i < N; i++) {
		if (A[i] - B > 0) {
			answer += (A[i] - B) / C;
			if ((A[i] - B) % C  != 0) {
				answer++;
			}
		}
	}

	cout << answer;

	return 0;
}
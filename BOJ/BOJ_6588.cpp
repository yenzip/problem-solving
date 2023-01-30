#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000000;
bool check[MAX + 1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	check[0] = check[1] = true;
	for (int i = 2; i <= MAX; i++) {
		if (!check[i]) {
			for (int j = i + i; j <= MAX; j += i) {
				check[j] = true;
			}
		}
	}

	while (1) {
		int N;
		int goldbach = 0;
		cin >> N;

		if (N == 0) {
			break;
		}

		for (int i = 2; i <= N; i++) {
			if (!check[i] && !check[N-i]) {
				cout << N << " = " << i << " + " << N - i << '\n';
				goldbach = 1;
				break;
			}
		}

		if (!goldbach) {
			cout << "Goldbach's conjecture is wrong" << '\n';
		}
	}

	return 0;
}
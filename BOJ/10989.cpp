#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int count[10001] = { 0 };
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		count[num]++;
	}

	for (int i = 1; i <= 10000; i++) {
		if (count[i]) {
			for (int j = 0; j < count[i]; j++) {
				cout << i << "\n";
			}
		}
	}

	return 0;
}
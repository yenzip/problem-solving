#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	string map;
	cin >> N >> map;

	int cnt = 0;
	for (int i = 0; i < N - 1; i++) {
		if (map[i] == 'E' && map[i + 1] == 'W') {
			cnt++;
			i++;
		}
	}

	cout << cnt;

	return 0;
}
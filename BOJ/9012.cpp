#include <bits/stdc++.h>
using namespace std;

int T;
string VPS;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	while (T--) {
		cin >> VPS;

		int size = 0;	// 스택의 크기
		bool isVPS = true;

		for (auto c : VPS) {
			if (c == '(') {
				size++;
			}
			else {
				if (size) {
					size--;
				}
				else {
					isVPS = false;
					break;
				}
			}
		}

		string answer = "YES";

		if (size || !isVPS) {
			answer = "NO";
		}

		cout << answer << "\n";
	}

	return 0;
}
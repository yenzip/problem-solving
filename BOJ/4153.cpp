#include <bits/stdc++.h>
using namespace std;

int tri[3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (1) {
		for (int i = 0; i < 3; i++) {
			cin >> tri[i];
		}

		if (tri[0] == 0 && tri[1] == 0 && tri[2] == 0) {
			break;
		}

		sort(tri, tri + 3);

		int a2 = tri[0] * tri[0];
		int b2 = tri[1] * tri[1];
		int c2 = tri[2] * tri[2];

		if (a2 + b2 == c2) {
			cout << "right\n";
		}
		else {
			cout << "wrong\n";
		}
	}

	return 0;
}
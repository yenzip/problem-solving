#include <bits/stdc++.h>
using namespace std;

int T;
string Info;
bool S[14];
bool D[14];
bool H[14];
bool C[14];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> Info;
		memset(S, false, sizeof(S));
		memset(D, false, sizeof(D));
		memset(H, false, sizeof(H));
		memset(C, false, sizeof(C));

		cout << '#' << t << ' ';
		bool error = false;
		int s = 13, d = 13, h = 13, c = 13;
		for (int i = 0; i < Info.size(); i += 3) {
			char type = Info[i];
			int num = stoi(Info.substr(i + 1, 2));
			if (type == 'S') {
				if (!S[num]) {
					S[num] = true;
					s--;
				}
				else {
					cout << "ERROR\n";
					error = true;
					break;
				}
			}
			else if (type == 'D') {
				if (!D[num]) {
					D[num] = true;
					d--;
				}
				else {
					cout << "ERROR\n";
					error = true;
					break;
				}
			}
			else if (type == 'H') {
				if (!H[num]) {
					H[num] = true;
					h--;
				}
				else {
					cout << "ERROR\n";
					error = true;
					break;
				}
			}
			else if (type == 'C') {
				if (!C[num]) {
					C[num] = true;
					c--;
				}
				else {
					cout << "ERROR\n";
					error = true;
					break;
				}
			}
		}
		if (!error) {
			cout << s << ' ' << d << ' ' << h << ' ' << c << '\n';
		}
	}

	return 0;
}
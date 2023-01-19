#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;

	cin >> T;

	while (T--) {
		string str;
		int size = 0;	// size: ���� ������
		int isVPS = 1;	// isVPS: �ùٸ� ��ȣ ���ڿ����� Ȯ��

		cin >> str;

		for (char ch : str) {
			if (ch == '(') {
				size++;
			}
			else {
				if (size == 0) {
					isVPS = 0;
					break;
				}
				else {
					size--;
				}
			}
		}
		if (isVPS && !size) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
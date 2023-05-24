#include <bits/stdc++.h>
using namespace std;

int N;
int tree[26][2];

void preOrder(int now) {
	if (now == -1) {
		return;
	}
	cout << char('A' + now);
	preOrder(tree[now][0]);
	preOrder(tree[now][1]);
}

void inOrder(int now) {
	if (now == -1) {
		return;
	}
	inOrder(tree[now][0]);
	cout << char('A' + now);
	inOrder(tree[now][1]);
}

void postOrder(int now) {
	if (now == -1) {
		return;
	}
	postOrder(tree[now][0]);
	postOrder(tree[now][1]);
	cout << char('A' + now);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		char root, left, right;
		cin >> root >> left >> right;

		int idx = root - 'A';
		left == '.' ? tree[idx][0] = -1 : tree[idx][0] = left - 'A';
		right == '.' ? tree[idx][1] = -1 : tree[idx][1] = right - 'A';
	}

	preOrder(0);
	cout << "\n";

	inOrder(0);
	cout << "\n";

	postOrder(0);
	cout << "\n";

	return 0;
}
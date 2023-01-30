#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000000;
bool check[MAX + 1];	// �����佺�׳׽��� ü

int main() {
	int M, N;
	cin >> M >> N;

	check[0] = check[1] = true;	// �Ҽ��� ��� ����
	for (int i = 2; i <= N; i++) {
		if (!check[i]) {
			for (int j = i * 2; j <= N; j += i) {	
				check[j] = true;
			}
		}
	}

	for (int i = M; i <= N; i++) {
		if (!check[i]) {
			cout << i << '\n';
		}
	}

	return 0;

}
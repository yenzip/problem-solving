#include <bits/stdc++.h>
using namespace std;

struct Medal {
	int id;
	int gold;
	int silver;
	int bronze;
};

int N, K;
Medal A[1001];

bool compare(Medal a, Medal b) {
	if (a.gold == b.gold) {
		if (a.silver == b.silver) {
			if (a.bronze == b.bronze) {
				return a.id == K;	// 메달의 개수가 금, 은, 동 모두 같다면 K 먼저
			}
			return a.bronze > b.bronze;
		}
		return a.silver > b.silver;
	}
	return a.gold > b.gold;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int id, gold, silver, bronze;
		cin >> id >> gold >> silver >> bronze;
		A[i].id = id;
		A[i].gold = gold;
		A[i].silver = silver;
		A[i].bronze = bronze;
	}

	sort(A, A + N, compare);

	int rank = 1;

	for (int i = 0; i < N; i++, rank++) {
		if (A[i].id == K) {
			break;
		}
	}

	cout << rank;

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000000;
bool check[MAX + 1];	// 에러토스테네스의 체

int main() {
	int M, N;
	cin >> M >> N;

	check[0] = check[1] = true;	// 소수의 배수 제거
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
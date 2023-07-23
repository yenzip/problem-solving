#include <bits/stdc++.h>
using namespace std;

int N, M, sex, number;
int A[101];	// 스위치의 상태

void switchOnOff(int x) {
	A[x] = A[x] ? 0 : 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> sex >> number;
		
		if (sex == 1) {	// 남학생
			for (int j = number; j <= N; j += number) {
				switchOnOff(j);
			}
		}
		else {	// 여학생
			switchOnOff(number);
			int j = 1;
			while (number - j > 0 && number + j <= N && A[number - j] == A[number + j]) {
				switchOnOff(number - j);
				switchOnOff(number + j);
				j++;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << A[i] << " ";
		if (i % 20 == 0) {
			cout << "\n";
		}
	}
	
	return 0;
}


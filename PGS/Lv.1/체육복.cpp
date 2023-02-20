#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;

	vector<int> v(n + 1, 0);

	for (auto i : reserve) {
		v[i] += 1;
	}

	for (auto i : lost) {
		v[i] -= 1;
	}

	for (int i = 1; i <= n; i++) {
		if (v[i] == -1) {
			if (v[i - 1] == 1) {
				v[i - 1] = v[i] = 0;
			}
			else if (v[i + 1] == 1) {
				v[i + 1] = v[i] = 0;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (v[i] >= 0) {
			answer++;
		}
	}

	return answer;
}
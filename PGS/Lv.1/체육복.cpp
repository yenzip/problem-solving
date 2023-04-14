#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;

	vector<int> own(n + 1, 1);
	for (int i = 0; i < lost.size(); i++) {
		own[lost[i]] -= 1;
	}
	for (int i = 0; i < reserve.size(); i++) {
		own[reserve[i]] += 1;	// * ���� ü������ ������ �л��� ������ ���� ��찡 ����
	}

	for (int i = 1; i <= n; i++) {
		if (own[i] == 0) {
			if (i - 1 >= 1 && own[i - 1] == 2) {
				own[i - 1] = own[i] = 1;
			}
			else if (i + 1 <= n && own[i + 1] == 2) {
				own[i + 1] = own[i] = 1;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (own[i] >= 1) {
			answer++;
		}
	}

	return answer;
}
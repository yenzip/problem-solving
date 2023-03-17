#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
	int answer = 0;

	stack<int> s;	// ���� �����̾� ��Ʈ

	int idx = 0;	// order index	
	for (int i = 1; i <= order.size(); i++) {	// �����̾� ��Ʈ
		if (!s.empty() && s.top() == order[idx]) {
			answer++;
			idx++;
			s.pop();
		}
		if (order[idx] == i) {
			answer++;
			idx++;
		}
		else {
			s.push(i);
		}
	}

	while (!s.empty() && s.top() == order[idx++]) {
		answer++;
		s.pop();
	}

	return answer;
}
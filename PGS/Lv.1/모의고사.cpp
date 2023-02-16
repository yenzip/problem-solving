#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> s1 = { 1, 2, 3, 4, 5 };
vector<int> s2 = { 2, 1, 2, 3, 2, 4, 2, 5};
vector<int> s3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

vector<int> solution(vector<int> answers) {
	vector<int> answer;

	int n1 = s1.size();
	int n2 = s2.size();
	int n3 = s3.size();
	vector<int> correct(3, 0);

	for (int i = 0; i < answers.size(); i++) {
		if (s1[i % n1] == answers[i]) {
			correct[0]++;
		}
		if (s2[i % n2] == answers[i]) {
			correct[1]++;
		}
		if (s3[i % n3] == answers[i]) {
			correct[2]++;
		}
	}

	int max = *max_element(correct.begin(), correct.end());
	for (int i = 0; i < 3; i++) {
		if (correct[i] == max) {
			answer.push_back(i + 1);
		}
	}

	return answer;
}
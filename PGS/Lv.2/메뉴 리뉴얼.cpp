#include <string>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;

map<string, int> m;
bool visited[10];
int max_value;

void dfs(string order, int idx, string course, int len) {
	if (course.size() == len) {
		sort(course.begin(), course.end());
		m[course]++;
		if (max_value < m[course]) {
			max_value = m[course];
		}
		return;
	}

	for (int i = 0; i < order.size(); i++) {
		if (!visited[i] && idx < i) {
			visited[i] = true;
			dfs(order, i, course + order[i], len);
			visited[i] = false;
		}
	}
}

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;

	for (auto c : course) {
		max_value = 0;
		m.clear();
		for (auto o : orders) {
			memset(visited, false, sizeof(visited));
			dfs(o, -1, "", c);
		}

		if (max_value >= 2) {
			for (auto i : m) {
				if (i.second == max_value) {
					answer.push_back(i.first);
				}
			}
		}
	}

	sort(answer.begin(), answer.end());

	return answer;
}
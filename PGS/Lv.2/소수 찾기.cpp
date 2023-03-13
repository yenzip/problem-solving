#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> s;
bool visited[7];

void dfs(string numbers, string snum) {
	if (!snum.empty()) {
		s.insert(stoi(snum));
	}

	for (int i = 0; i < numbers.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(numbers, snum + numbers[i]);
			visited[i] = false;
		}
	}
	return;
}

bool isPrime(int n) {
	if (n < 2) {
		return false;
	}
	for (int i = 2; i*i <= n; i++) {
		if (n %i == 0) {
			return false;
		}
	}
	return true;
}

int solution(string numbers) {
	int answer = 0;
	
	dfs(numbers, "");

	for (auto i : s) {
		if (isPrime(i)) {
			answer++;
		}
	}

	return answer;
}
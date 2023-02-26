#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;

	sort(people.begin(), people.end());

	int f = 0, b = people.size() - 1;	// front, back
	while (f <= b) {
		if (people[f] + people[b] <= limit) {
			f++;
			b--;
		}
		else {
			b--;
		}
		answer++;
	}

	return answer;
}
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
	int answer = 0;

	vector<int> v;
	for (auto i : ingredient) {
		if (!v.empty() && i == 1 && v[v.size() - 1] == 3 && v[v.size() - 2] == 2 && v[v.size() - 3] == 1) {
			answer++;
			v.pop_back();	// 3
			v.pop_back();	// 2
			v.pop_back();	// 1
		}
		else {
			v.push_back(i);
		}
	}

	return answer;
}
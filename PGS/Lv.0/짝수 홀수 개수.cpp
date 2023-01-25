#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
	vector<int> answer(2, 0);
	for (int num : num_list) {
		answer[num % 2]++;
	}
	return answer;
}
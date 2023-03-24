#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{

	map<int, int> m;
	for (auto num : nums) {
		m[num]++;
	}

	return nums.size() / 2 <= m.size() ? nums.size() / 2 : m.size();
}
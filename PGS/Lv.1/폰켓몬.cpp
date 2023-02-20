#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
	set<int> s;
	for (auto i : nums) {
		s.insert(i);
	}

	return min(nums.size() / 2, s.size());
}
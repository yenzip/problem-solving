#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string lower_case(string s) {
	for (auto& i : s) {
		i = tolower(i);
	}
	return s;
}

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;

	vector<string> cache(cacheSize);
	for (auto& city : cities) {
		city = lower_case(city);
		if (find(cache.begin(), cache.end(), city) != cache.end()) {	// cache_hit
			cache.erase(remove(cache.begin(), cache.end(), city), cache.end());
			cache.push_back(city);
			answer += 1;
		}
		else {	// cache_miss
			if (cacheSize != 0) {
				if (cache.size() == cacheSize) {	// LRU
					cache.erase(cache.begin());
				}
				cache.push_back(city);
			}
			answer += 5;
		}
	}

	return answer;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
	int answer = 0;

	transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
	transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

	vector<string> v1;
	for (int i = 0; i < str1.size() - 1; i++) {
		if (isalpha(str1[i]) && isalpha(str1[i + 1])) {
			v1.push_back(str1.substr(i, 2));
		}
	}
	sort(v1.begin(), v1.end());

	vector<string> v2;
	for (int i = 0; i < str2.size() - 1; i++) {
		if (isalpha(str2[i]) && isalpha(str2[i + 1])) {
			v2.push_back(str2.substr(i, 2));
		}
	}
	sort(v2.begin(), v2.end());

	vector<string> un;	// 합집합
	un.resize(v1.size() + v2.size());
	auto iter = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), un.begin());
	un.erase(iter, un.end());	// 남은 공간 제거

	vector<string> ints;	// 교집합
	ints.resize(v1.size() + v2.size());
	iter = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), ints.begin());
	ints.erase(iter, ints.end());

	int ints_s = ints.size();
	int un_s = un.size();
	double J = !ints_s && !un_s ? 1 : ints_s * 1.0 / un_s;

	J *= 65536;

	answer = int(J);

	return answer;
}
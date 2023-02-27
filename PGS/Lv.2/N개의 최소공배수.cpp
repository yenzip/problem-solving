#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int solution(vector<int> arr) {
	int answer = 0;

	for (int i = 1; i < arr.size(); i++) {
		arr[i] = (arr[i - 1] * arr[i]) / gcd(arr[i - 1], arr[i]);
	}

	answer = arr[arr.size() - 1];

	return answer;
}
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int num = 1;

	for (int i = 1; i <= n; i++, num++) {
		while (num % 3 == 0 || to_string(num).find('3') != string::npos) {
			num++;
		}
	}

	return num - 1;
}
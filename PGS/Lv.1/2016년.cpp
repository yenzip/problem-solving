#include <string>
#include <vector>
#include <numeric>

using namespace std;

vector<int> day = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
string week[7] = { "FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU" };

string solution(int a, int b) {

	int total = accumulate(day.begin(), day.begin() + a - 1, 0);
	total += b;

	return total % 7 == 0 ? week[6] : week[total % 7];
}
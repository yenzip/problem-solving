#include <string>
#include <vector>

using namespace std;

vector<int> v = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
vector<string> week = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };


string solution(int a, int b) {
	int day = 0;
	for (int i = 0; i < a; i++) {
		day += v[i];
	}

	day += b;

	return week[(day % 7 + 4) % 7];
}
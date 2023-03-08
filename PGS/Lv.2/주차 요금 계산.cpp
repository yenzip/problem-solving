#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
	vector<int> answer;

	map<string, vector<pair<string, string>>> m;	// 차랑번호, (입/출차, 시각)
	for (auto rec : records) {
		stringstream ss(rec);
		string car_num, time, in_out;
		ss >> time >> car_num >> in_out;
		m[car_num].push_back({ in_out, time });
	}

	for (auto i : m) {
		int min = 0;	// 누적 시간
		int fare = fees[1];	// 요금
		for (int j = 0; j < i.second.size(); j += 2) {
			int hour1 = stoi(i.second[j].second.substr(0, 2));
			int	min1 = stoi(i.second[j].second.substr(3, 2));

			int hour2, min2;
			if (j + 1 < i.second.size()) {
				hour2 = stoi(i.second[j + 1].second.substr(0, 2));
				min2 = stoi(i.second[j + 1].second.substr(3, 2));
			}
			else {
				hour2 = 23;
				min2 = 59;
			}

			if (min2 < min1) {
				hour2--;
				min += min2 - min1 + 60;
			}
			else {
				min += min2 - min1;
			}
			min += (hour2 - hour1) * 60;
		}

		if (min > fees[0]) {
			double tmp = (min - fees[0]) * 1.0 / fees[2];
			fare += ceil(tmp) * fees[3];
		}

		answer.push_back(fare);
	}

	return answer;
}
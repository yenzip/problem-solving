#include <bits/stdc++.h>

using namespace std;

bool visited[100];
vector<string> priority;

void dfs(vector<char> op, string s) {	// 연산자 우선순위
	if (s.size() == op.size()) {
		priority.push_back(s);
		return;
	}

	for (auto i : op) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(op, s + i);
			visited[i] = false;
		}
	}
}

long long calc(long long a, long long b, char op) {	// 계산
	if (op == '+') {
		return a + b;
	}
	else if (op == '-') {
		return a - b;
	}
	else if (op == '*') {
		return a * b;
	}
}

long long solution(string expression) {
	long long answer = 0;

	string tmp;
	vector<long long> num;
	vector<char> op;	// 연산자
	vector<char> op_tmp;
	for (auto exp : expression) {
		if (exp == '+' || exp == '-' || exp == '*') {
			op.push_back(exp);
			num.push_back(stoi(tmp));
			tmp.clear();
			if (!op_tmp.empty() && find(op_tmp.begin(), op_tmp.end(), exp) != op_tmp.end()) {
				continue;
			}
			else {
				op_tmp.push_back(exp);
			}
		}
		else {
			tmp += exp;
		}
	}
	if (!tmp.empty()) {
		num.push_back(stoi(tmp));
	}

	dfs(op_tmp, "");	// 연산자 우선순위

	for (auto p : priority) {
		vector<long long> num_tmp(num);
		op_tmp = op;
		for (auto o : p) {
			for (int i = 0; i < op_tmp.size();) {
				if (o == op_tmp[i]) {
					long long result = calc(num_tmp[i], num_tmp[i + 1], o);

					num_tmp.erase(num_tmp.begin() + i);
					num_tmp.erase(num_tmp.begin() + i);
					num_tmp.insert(num_tmp.begin() + i, result);

					op_tmp.erase(op_tmp.begin() + i);
				}
				else {
					i++;
				}
			}
		}
		answer = max(answer, abs(num_tmp[0]));
	}

	return answer;
}
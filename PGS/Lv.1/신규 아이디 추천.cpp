#include <string>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

string solution(string new_id) {

	// 1�ܰ� + 2�ܰ�
	for (auto& i : new_id) {
		i = tolower(i);
		if (!(islower(i) || isdigit(i) || i == '-' || i == '_' || i == '.')) { // ��� ������ ���ڰ� �ƴϸ� �������� �ٲٱ�
			i = ' ';
		}
	}

	// 2�ܰ� - ����(��� �Ұ����� ����) ����
	new_id.erase(remove(new_id.begin(), new_id.end(), ' '), new_id.end());

	// 3�ܰ�
	new_id = regex_replace(new_id, regex("[.]+"), ".");

	// 4�ܰ�
	if (new_id[0] == '.') {
		new_id.erase(0, 1);
	}
	if (!new_id.empty() && new_id[new_id.size() - 1] == '.') {
		new_id.pop_back();
	}

	// 5�ܰ�
	if (new_id.empty()) {
		new_id += 'a';
	}

	// 6�ܰ�
	if (new_id.size() > 15) {
		new_id = new_id.substr(0, 15);
		if (new_id[new_id.size() - 1] == '.') {
			new_id.pop_back();
		}
	}

	// 7�ܰ�
	if (new_id.size() <= 2) {
		char c = new_id.back();
		while (new_id.size() != 3) {
			new_id += c;
		}
	}
	
	return new_id;
}
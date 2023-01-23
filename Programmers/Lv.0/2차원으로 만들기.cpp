#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    vector<vector<int>> answer;

    answer.resize(num_list.size() / n);

    int i = 0, cnt = 0;
    for (int num : num_list) {
        if (cnt == n) {
            cnt = 0;
            i++;
        }
        answer[i].push_back(num);
        cnt++;
    }
    return answer;
}
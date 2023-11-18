class Solution {
public:
    static bool comp(vector<string> &a, vector<string> &b) {
        return a.size() < b.size();
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        map<string, vector<string>> m;
        
        for(string str : strs) {
            string word = str;
            sort(str.begin(), str.end());
            m[str].push_back(word);
        }
        
        answer.resize(m.size());
        int idx = 0;
        
        for(auto &entry : m) {
            sort(entry.second.begin(), entry.second.end());
            for(auto word : entry.second) {
                answer[idx].push_back(word);
            }
            idx++;
        }
        
        sort(answer.begin(), answer.end(), comp);
        
        return answer;
    }
};
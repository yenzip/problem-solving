class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size(), 0);

        stack<int> stk;
        stk.push(0);

        for(int i = 1; i < temperatures.size(); i++) {
            while(!stk.empty() && temperatures[stk.top()] < temperatures[i]) {
                answer[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }

        return answer;
    }
};
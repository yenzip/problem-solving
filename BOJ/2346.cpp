#include <bits/stdc++.h>
using namespace std;

int N, x;
deque<pair<int, int>> dq;
vector<int> answer;

int main() {
    
    cin >> N;
    
    for(int i = 1; i <= N; i++) {
        cin >> x;
        dq.push_back({i, x});
    }
    
    while(!dq.empty()) {
        int num = dq.front().first;
        int move = dq.front().second;
        answer.push_back(num);
        dq.pop_front();
        
        if(move > 0) {
            for(int i = 0; i < move - 1; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        } else {
            for(int i = 0; i < move * (-1); i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
    
    for(int i = 0; i < N; i++) {
        cout << answer[i] <<" ";
    }
    
    return 0;
}
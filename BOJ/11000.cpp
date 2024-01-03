#include <bits/stdc++.h>
using namespace std;

int N;
int s, e;
vector<pair<int, int>> v;   // {start, end}
priority_queue<int, vector<int>, greater<int>> pq;  // 종료 시간 기준으로 오름차순 정렬

int main() {
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> s >> e;
        v.push_back({s, e});
    }
    
    sort(v.begin(), v.end());   // 시작 시간 기준으로 오름차순 정렬
    
    for(auto &lecture : v) {
        if(!pq.empty() && pq.top() <= lecture.first) {  // 현재 강의의 종료 시간이 강의의 시작 시간보다 빠르다면, 기존 강의실 사용
            pq.pop();
        }
        pq.push(lecture.second);    // 아니라면, 새로운 강의실 추가
    }
    
    cout << pq.size();
    
    return 0;
}
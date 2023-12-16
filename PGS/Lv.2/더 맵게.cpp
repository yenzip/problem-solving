#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq;  // 최소힙 우선순위 큐 (default: 최대힙)
    int answer = 0;
    
    for(int scov : scoville) {
        pq.push(scov);
    }
    
    while(pq.top() < K) {
        if(pq.size() < 2) {
            break;
        }
        
        int s1 = pq.top();
        pq.pop();
        int s2 = pq.top();
        pq.pop();
            
        pq.push(s1 + s2 * 2);
        answer++;
    }
    
    return pq.top() < K ? -1 : answer;
}
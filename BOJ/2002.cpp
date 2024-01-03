#include <bits/stdc++.h>
using namespace std;

int N;
string car;
map<string, int> m; // in {car, order}
vector<string> out;
int answer;

int main() {
    cin >> N;
    
    out.resize(N);
    
    for(int i = 0; i < N; i++) {
        cin >> car;
        m[car] = i;
    }
    
    for(int i= 0; i < N; i++) {
        cin >> out[i];
    }
    
    for(int i = 0; i < N - 1; i++) {
        for(int j = i + 1; j < N; j++) {
            if(m[out[i]] > m[out[j]]) {
                answer++;
                break;
            }
        }
    }
    
    cout << answer;
    
    return 0;
}
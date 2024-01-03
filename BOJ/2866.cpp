#include <bits/stdc++.h>
using namespace std;

int R, C;
vector<string> v;
unordered_set<string> st;
int answer;

int main() {
    cin >> R >> C;

    v.resize(R);
    
    for (int i = 0; i < R; ++i) {
        cin >> v[i];
    }

    for (int j = 0; j < C; ++j) {
        string s;
        for (int i = 0; i < R; ++i) {
            s += v[i][j];
        }
        st.insert(s);
    }
    
    int row = 0;
    while (row < R - 1) {
        unordered_set<string> tmp;
        for (auto &s : st) {
            tmp.insert(s.substr(1));    // 가장 위의 행에 해당하는 문자를 제외한 부분 문자열
        }
        st.swap(tmp);
        
        if(st.size() != C) {
            break;
        }
        
        answer++;
        row++;
    }

    cout << answer << '\n'; 

    return 0;
}
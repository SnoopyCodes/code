#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int Q; cin >> Q;
    string p; cin >> p;
    vector<char> up;
    int N = p.size();
    for (int i = 0; i < N; i++) {
        if (p[i] < 97) { up.push_back(p[i]); }
    }
    int answer = 0;
    for (int q = 0; q < Q; q++) {
        string s; cin >> s;
        int M = s.size();
        //p must be subsequence of s
        //and the upper case letters must match exactly
        vector<int> filter;
        for (int i = 0; i < M; i++) {
            if (s[i] < 97) { filter.push_back(s[i]); }
        }
        if (filter.size() != up.size()) { continue; }
        bool valid = true;
        for (int i = 0; i < up.size(); i++) {
            if (filter[i] != up[i]) { valid = false; break; }
        }
        if (!valid) { continue; }
        //now, do subsequence matching
        int j = 0;
        for (int i = 0; i < M; i++) {
            if (j < N && s[i] == p[j]) { j++; }
        }
        answer += j == N;
    }
    cout << answer << "\n";
}
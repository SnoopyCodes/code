#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int Q; cin >> Q;
    string s; cin >> s;
    int N = s.size();
    //iterating through s each time is OK
    int answer = 0;
    for (int q = 0; q < Q; q++) {
        string t; cin >> t; //idk why i use t
        int j = 0;
        int M = t.size();
        for (int i = 0; i < N; i++) {
            if (j != M && s[i] == t[j]) { j++; }
        }
        answer += j == M;
    }
    cout << answer << "\n";
}
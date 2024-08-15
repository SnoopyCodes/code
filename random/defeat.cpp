#include <bits/stdc++.h>

using namespace std;
void solve() {
    int N; cin >> N;
    string s; cin >> s;
    vector<bool> lit(N);
    bool right = false;
    for (int i = 0; i < N; i++) {
        if (right) { lit[i] = true; }
        if (s[i] == 'L') { right = true; }
    }
    bool left = false;
    for (int i = N - 1; i > -1; i--) {
        if (left) { lit[i] = true; }
        if (s[i] == 'R') { left = false; }
    }
    
    //so loop through left
    //
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T) { T--; solve(); }
}